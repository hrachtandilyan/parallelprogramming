using Distance_Calculator.Models;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Distance_Calculator.FileOperations;
using Distance_Calculator.Core;
using System.Threading;
using System.Reflection;

namespace Distance_Calculator
{
    public partial class MainWindow : Window
    {
        private VectorsListModel queryVectorsList;
        private VectorsListModel datasetVectorsList;
        private Logger logger;

        public MainWindow()
        {
            InitializeComponent();
            InitView();
        }

        public void InitView()
        {
            logger = new Logger();
            logger.ProgramLogDelete();

            Watch();

            logger.LogToProgram("Vector distance calculator is ready");
            logger.LogToProgram("Select csv files with vectors.");
        }

        #region Buttons Click Handlers

        private void ButtonBrowseQueryFile_OnClick(object sender, RoutedEventArgs e)
        {
            var dlg = new Microsoft.Win32.OpenFileDialog
            {
                DefaultExt = ".csv",
                Filter = "CSV Files (*.csv)|*.csv"
            };
            var result = dlg.ShowDialog();
            if (result == true)
            {
                var fileName = dlg.FileName;
                var input = new Input();
                queryVectorsList = input.ReadfromCsv(fileName);
                textBoxQueryInput.Text = fileName;
                logger.LogToProgram($"Inputed query vector with vector length: {queryVectorsList.VectorsLength} and count: {queryVectorsList.VectorsCount}");
                if (textBoxDatasetInput.Text == String.Empty)
                {
                    logger.LogToProgram("Select dataset vector csv.");
                }
                else
                {
                    logger.LogToProgram("Begin calculation.");
                }
                textBlockQueryVectorLength.Text = $"Length: {queryVectorsList.VectorsLength}";
                textBlockQueryVectorCount.Text = $"Count: {queryVectorsList.VectorsCount}";
            }
        }

        private void ButtonBrowseDatasetFile_OnClick(object sender, RoutedEventArgs e)
        {
            var dlg = new Microsoft.Win32.OpenFileDialog
            {
                DefaultExt = ".csv",
                Filter = "CSV Files (*.csv)|*.csv"
            };
            var result = dlg.ShowDialog();
            if (result == true)
            {
                var fileName = dlg.FileName;
                var input = new Input();
                datasetVectorsList = input.ReadfromCsv(fileName);
                textBoxDatasetInput.Text = fileName;
                logger.LogToProgram($"Inputed dataset vector with vector length: {datasetVectorsList.VectorsLength} and count: {datasetVectorsList.VectorsCount}");
                if (textBoxQueryInput.Text == String.Empty)
                {
                    logger.LogToProgram("Select query vector csv.");
                }
                else
                {
                    logger.LogToProgram("Begin calculation.");
                }
                textBlockDatasetVectorLength.Text = $"Length: {datasetVectorsList.VectorsLength}";
                textBlockDatasetVectorCount.Text = $"Count: {datasetVectorsList.VectorsCount}";
            }
        }

        private void ButtonStartCalculation_OnClick(object sender, RoutedEventArgs e)
        {
            if (queryVectorsList != null && datasetVectorsList != null)
            {
                StartCalculator();
            }
            else
            {
                var randomizer = new Randomizer();

                if (queryVectorsList == null)
                {
                    if (datasetVectorsList != null)
                    {
                        logger.LogToProgram("No query csv file was inputed, generating random with dataset csv's length and count.");
                        queryVectorsList = randomizer.GenerateVectorsModel(datasetVectorsList.VectorsLength, datasetVectorsList.VectorsCount);
                    }
                    else
                    {
                        logger.LogToProgram("No query csv file was inputed, generating random with default length and count");
                        queryVectorsList = randomizer.GenerateVectorsModel(20, 20);    //temporary small
                    }
                }
                if (datasetVectorsList == null)
                {
                    if (queryVectorsList != null)
                    {
                        logger.LogToProgram("No dataset csv file was inputed, generating random with query csv's length and count.");
                        datasetVectorsList = randomizer.GenerateVectorsModel(queryVectorsList.VectorsLength, queryVectorsList.VectorsCount);
                    }
                    else
                    {
                        logger.LogToProgram("No dataset csv file was inputed, generating random with default length and count");
                        datasetVectorsList = randomizer.GenerateVectorsModel(20, 20);    //temporary small
                    }
                }

                StartCalculator();
            }
        }

        #endregion

        private void StartCalculator()
        {
            var calculator = new Calculator();
            new Thread(() =>
                calculator.StartCalculation(queryVectorsList, datasetVectorsList)
            ).Start();

            buttonBrowseQueryFile.IsEnabled = buttonBrowseDatasetFile.IsEnabled = false;
            textBoxDatasetInput.IsEnabled = textBoxQueryInput.IsEnabled = false;
            buttonStartCalculation.IsEnabled = false;
        }

        #region Functions for updating scrollViews

        private void Watch()
        {
            var watch = new FileSystemWatcher();
            watch.Path = System.IO.Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            watch.NotifyFilter = NotifyFilters.LastAccess | NotifyFilters.LastWrite;
            watch.Changed += new FileSystemEventHandler(OnChanged);
            watch.EnableRaisingEvents = true;
        }

        private void OnChanged(object sender, FileSystemEventArgs e)
        {
            if (e.FullPath == @"C:\Projects\Distance_Calculator\Distance_Calculator\bin\Debug\ProgramLog.txt")
            {
                ReadLogFile(e.FullPath, textBlockStatus, scrollView);
            }
            else if(e.FullPath == @"C:\Projects\Distance_Calculator\Distance_Calculator\bin\Debug\SimpleEngineL1Log.txt")
            {
                ReadLogFile(e.FullPath, textBlockStatusImplementationL1, scrollViewImplementationL1);
            }
            else if (e.FullPath == @"C:\Projects\Distance_Calculator\Distance_Calculator\bin\Debug\SimpleEngineL2Log.txt")
            {
                ReadLogFile(e.FullPath, textBlockStatusImplementationL2, scrollViewImplementationL2);
            }
            else if (e.FullPath == @"C:\Projects\Distance_Calculator\Distance_Calculator\bin\Debug\SimpleEngineHammingLog.txt")
            {
                ReadLogFile(e.FullPath, textBlockStatusImplementationHamming, scrollViewImplementationHamming);
            }
        }

        private void ReadLogFile(string path, TextBlock textBlock, ScrollViewer scrollViewer)
        {
            //todo fix some bug here
            var list = new List<string>();
            using (var fs = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite))
            {
                if (fs.Length > 1024)
                {
                    fs.Seek(-1024, SeekOrigin.End);
                    using (var sr = new StreamReader(fs))
                    {
                        string line;
                        while ((line = sr.ReadLine()) != null)
                        {
                            list.Add(line);
                        }
                        var combindedString = list.Last();
                        textBlock.Dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Normal,
                            new Action(delegate()
                            {
                                textBlock.Text += combindedString + Environment.NewLine;
                            }));
                        scrollViewer.Dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Normal,
                            new Action(delegate()
                            {
                                scrollViewer.ScrollToEnd();
                            }));
                    }
                }
                else
                {
                    using (var sr = new StreamReader(fs))
                    {
                        string line;
                        while ((line = sr.ReadLine()) != null)
                        {
                            list.Add(line);
                        }
                        var combindedString = list.Last();
                        textBlock.Dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Normal,
                            new Action(delegate ()
                            {
                                textBlock.Text += combindedString + Environment.NewLine;
                            }));
                        scrollViewer.Dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Normal,
                            new Action(delegate ()
                            {
                                scrollViewer.ScrollToEnd();
                            }));
                    }
                }
            }
        }

        #endregion

        
    }
}
