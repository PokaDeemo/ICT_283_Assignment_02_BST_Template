#include "MenuOption.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// empty default constructor
MenuOption::MenuOption()
{

}

// is to read/load the files data/files into the data structure
void MenuOption::ReadFile()
{
    // Variables
    ifstream infile, infile2;
    string fileName;
    // variables to store the value of day, m_Month, year, hour, minute, solar radiation, temperature
    string str, storeDay, storeMonth, storeYear, storeHour, storeMinute, storeSr, storeTemp, storeSpeed;

    // is for the map to restrict the searching within the data to load it.
    for(int y = 2006; y <= 2016; y++)
    {
        for(int m = 1; m <= 12; m++)
        {
            vector<WindLog> v;
            mapObject[y][m] = v;
        }
    }

    // to open the file and load it
    infile2.open("Data/met_index.txt");

    // If no file is found it will print-out this error statement
    if(!infile2)
    {
        cout << "error reading file!" << endl
             << "--- Program Ending!! ---" << endl;
        system("Pause");
    }
    else
    {
        // WHILE it is not end of the file
        while(!infile2.eof())
        {
            getline(infile2, fileName);
            // Print-out the Files name
            cout << "Loading File Data Of : " << fileName << endl;
            // open individual file one by one and store it into the map
            infile.open("Data/" + fileName);

            // If no individual file from the met_index.txt is found it will print-out this error statement
            if(!infile)
            {
                cout << "error reading file!" << endl
                     << "--- Program Ending!! ---" << endl;
                system("Pause");
            }

            // ignore first line containing the column headers
            infile.ignore(500, '\n');

            // reading the data file, and load it into the map
            while(!infile.eof())
            {
                // Check for End of Line and End of File
                if((infile.peek() == '\n') || infile.eof())
                {
                    getline(infile, str, '\n');
                    continue;
                }
                else
                {
                    // ELSE it will do this
                    getline(infile, storeDay, '/');
                    getline(infile, storeMonth, '/');
                    getline(infile, storeYear, ' ');

                    getline(infile, storeHour, ':');
                    getline(infile, storeMinute, ',');

                    // Ignore 9 column to get value of wind speed
                    for(int i = 0; i < 9; i++)
                    {
                        getline(infile, str, ',');
                    }
                    getline(infile, storeSpeed, ',');
                    getline(infile, storeSr, ',');

                    // Ignore 5 column to get the value of temperature
                    for(int i = 0; i < 5; i++)
                    {
                        getline(infile, str, ',');
                    }
                    getline(infile, storeTemp, '\n');

                    // Store the object into the mapObject
                    if(storeSpeed != "N/A" && storeSr != "N/A" && storeTemp != "N/A")
                    {
                        Date dateObject = Date (stoi(storeDay), stoi(storeMonth), stoi(storeYear));
                        Time timeObject = Time (stoi(storeHour), stoi(storeMinute));
                        Weather windObject = Weather(stof(storeSpeed), stof(storeSr), stof(storeTemp));
                        WindLog wl = WindLog(dateObject, timeObject, windObject);

                        mapObject[dateObject.GetYear()][dateObject.GetMonth()].push_back(wl); // Load the data into the map
                    }// END OF IF
                } // END OF ELSE
            } // END of 2nd While LOOP

            infile.close(); // Close the infile

        } // END of first While LOOP

        // Print-out Statement while the file is done loading
        cout << endl;
        cout << "--- File Loading Ended!! ---" << endl << endl;

    } // END OF ELSE
} // END OF READFILE()

// Display the average wind speed and ambient air temperature from infile month and year
void MenuOption::Option1()
{
    // Variables
    int m_Month,m_Year;
    float sumWS = 0.0; //value for calculation of wind speed
    float sumTemp = 0.0; //value for calculation of temperature
    int count = 0; //counter for total number of data
    Date dateObject;

    // Prompt for User Month Input
    cout<< "Enter a month please!. Between [1-12]: " << endl; //request user to type 1-12
    cin >> m_Month;

    // Validation check for the Month Input
    while(m_Month <= 0 || m_Month > 12) //allow input of 1-12 only
    {
        cout << "Invalid Month input! Try again...Enter in [1-12] digit: "; //request user to type 1-12 again
        cin >> m_Month;
    }

    // Prompt for User Year Input
    cout<< "Enter a year please!:" << endl;
    cin >> m_Year;

    // Validation check for the Year Input
    while(m_Year < 0)
    {
        cout <<"Invalid Year! Please Enter Again!!" << endl;
        cin >> m_Year;
    }

    // add speed and temperature
    for (int i=0; i < mapObject[m_Year][m_Month].size(); i++)
    {
        sumWS += mapObject[m_Year][m_Month].at(i).GetWeather().GetSpeed();
        sumTemp += mapObject[m_Year][m_Month].at(i).GetWeather().GetTemp();
        count++;
    }

    // Validation Check for the Data. If not data is found it will print-out this statement
    if(count == 0)
    {
        cout << dateObject.ConvertMonth(m_Month)<< " " << m_Year <<": " << "No Data" << endl;
    }
    else
    {
        // ELSE it will do the calculation of the average Wind Speed and Temperature
        float avgWind = (sumWS/count) *3.6; // convert m/s to km/h
        float avgTemp = sumTemp/count;

        cout << dateObject.ConvertMonth(m_Month) << " " << m_Year <<": "
             << fixed <<  setprecision(1) << avgWind <<" km/h, "
             << fixed << setprecision(1) <<  avgTemp << " degrees C" << endl;
    }
}//END OF Option1()

// Display the average wind speed and ambient air temperature of each month from the infile year.
void MenuOption::Option2()
{
    // Variables
    Date dateObject;
    int m_Year;
    float sumWS = 0.0;
    float sumTemp = 0.0;
    int count = 0;

    // Display Menu Option 2
    cout << "--- [Option 2] ---\n";

    // Prompt for User Year Input
    cout <<"Enter a specific Year please: " << endl;
    cin >> m_Year;

    // Validation Check of the Year User Input
    while(m_Year < 0)
    {
        cout <<"Invalid Year! Please Enter Again!!" << endl;
        cin >> m_Year;
    }

    // Display User Year Input
    cout << m_Year << endl;

    // Average Speed and Temperature Calculations
    for(int i = 1; i <= 12; i++)
    {
        // Resetting the variables for each month
        sumWS = 0;
        sumTemp = 0;
        count = 0;

        // Add Speed and Temperature
        for(int j = 0; j < mapObject[m_Year][i].size(); j++)
        {
            sumWS += mapObject[m_Year][i].at(j).GetWeather().GetSpeed();
            sumTemp += mapObject[m_Year][i].at(j).GetWeather().GetTemp();
            count++;
        }

        // Validation Check for the Data. If not data is found it will print-out this statement
        if(count == 0)
        {
            cout << dateObject.ConvertMonth(i) << " : No Data Found! " << endl;
        }
        else
        {
            // ELSE it will do the calculation of the average Wind Speed and Temperature
            float avgWind = (sumWS / count) * 3.6;
            float avgTemp = sumTemp / count;
            cout << dateObject.ConvertMonth(i) << " " << m_Year << ": "
                 << fixed << setprecision(1) << avgWind << " km/h, "
                 << fixed << setprecision(1) << avgTemp << " degree C: " << endl;
        }
    } // END OF FOR LOOP

} // END OF option2()

// Display the total solar radiation of each month from the infile year
void MenuOption::Option3()
{
    // Variables
    Date dateObject;
    int m_Year;
    float sumSR = 0.0;
    int count = 0;

    // Display Menu Option 3
    cout << "--- [Option 3] ---\n";

    // Prompt for User Year Input
    cout <<"Enter a specific Year please: " << endl;
    cin >> m_Year;

    // Validation check of the year user input
    while(m_Year < 0)
    {
        cout <<"Invalid Year! Please Enter Again!!" << endl;
        cin >> m_Year;
    }

    // Display User Year Input
    cout << m_Year << endl;

    // Calculate the total solar radiation
    for(int i = 1; i <= 12; i++)
    {
        // Reseting the variables for each month
        sumSR = 0;
        count = 0;

        // add solar radiation of each month
        for(int j = 0; j < mapObject[m_Year][i].size(); j++)
        {
            if(mapObject[m_Year][i].at(j).GetWeather().GetSolar() >= 100)
            {
                sumSR += mapObject[m_Year][i].at(j).GetWeather().GetSolar();
                count++;
            }
        }

        // Validation Check for the Data. If not data is found it will print-out this statement
        if(count == 0)
        {
            cout << dateObject.ConvertMonth(i) << " : No Data Found!" << endl;
        }
        else
        {
            // ELSE it will do the calculation of the average solar radiation
            float totalSolarRadiation = sumSR / 6000;
            cout << dateObject.ConvertMonth(i) << ": "
                 << fixed <<setprecision(1) << totalSolarRadiation << " kWh/m2 " << endl;
        }
    } // END OF FOR

} // END OF option3()

// Print into file the average wind speed, ambient air temperature and total solar radiation of each month from infile year.

void MenuOption::Option4()
{
    // Variables
    int m_Year;
    int count = 0;
    float sumSR = 0.0;
    float sumWS = 0.0;
    float sumTemp = 0.0;
    Date dateObject;
    ofstream output;
    bool Empty = true;

    // Display Menu Option 4
    cout << "--- [Option 4] ---\n";

    // Prompt for user Year Input
    cout <<"Enter a specific year please: " << endl;
    cin >> m_Year;

    // Validation check for the Year
    while(m_Year < 0)
    {
        cout <<"Invalid Year! Please Enter Again!!" << endl;
        cin >> m_Year;
    }

    // Open the output file
    output.open("Data/WindTempSolar.csv");
    output << m_Year << endl; // Display User Input Year

    for(int i = 1; i <= 12; i++)
    {
        // Reset the variables for each month
        sumSR = 0;
        sumWS = 0;
        sumTemp = 0;
        count = 0;

        // Add the wind speed, temperature and total solar radiation.
        for(int j = 0; j < mapObject[m_Year][i].size(); j++)
        {
            sumWS += mapObject[m_Year][i].at(j).GetWeather().GetSpeed();
            sumTemp += mapObject[m_Year][i].at(j).GetWeather().GetTemp();
            if(mapObject[m_Year][i].at(j).GetWeather().GetSolar() >= 100)
            {
                sumSR += mapObject[m_Year][i].at(j).GetWeather().GetSolar();
            }
            count++;
        }

        // Calculation of the average Speed, Temperature and Solar Radiation
        if(count != 0)
        {
            Empty = false;
            float avgWind = (sumWS/count) * 3.6;
            float avgTemp = sumTemp / count;
            float totalSolarRadiation = sumSR / 6000;

            // print the output into a csv format file.
            output << dateObject.ConvertMonth(i) << "\n Avg WS: " << ","
                   << fixed << setprecision(1) << avgWind << "\n Avg Temp: " <<","
                   << fixed << setprecision(1) << avgTemp << "\n Avg SR: " << ","
                   << fixed << setprecision(1) << totalSolarRadiation << endl;
        }
    } // END OF FOR LOOP

    // If it has no data it will print-out this statement.
    if(Empty)
        output << "Invalid Data/No Data output";

    // Close the output file
    output.close();
    cout << " Finish output the data into [CSV FORMAT]!." << endl;

} // END OF option4()

void MenuOption::Option5()
{
    // Variables
    BST <double> srBST;
    string input;
    string str;
    bool data = false;
    int tempDay = 0;
    double tempSolar = 0.0;
    int m_Day = 0;
    int m_Month = 0;
    int m_Year = 0;

    // Display Menu Option 5
    cout << "--- [Option 5] ---\n";

    // Prompt for user input for the date
    cout <<"Enter a date in [dd/m/yyyy/] format please!: " << endl;
    cin >> input;

    // Using this to copy the string that enter by the user input.
    istringstream iss(input);

    // Get each of those individual string in dd/mm/yyyy format.
    getline(iss, str, '/');
    m_Day = stoi(str);

    getline(iss, str, '/' );
    m_Month = stoi(str);

    getline(iss, str );
    m_Year = stoi(str);

    cout << endl;
    cout << "--- [Result] ---\n"
         << "\nDate: "<< m_Day << "/" << m_Month << "/" << m_Year << endl;

    // insert data matching input date into BST
    for( int i = 0; i < mapObject[m_Year][m_Month].size(); i++ )
    {
        tempDay = mapObject[m_Year][m_Month].at(i).GetDate().GetDay();
        if( tempDay == m_Day )
        {
            data = true;
            srBST.Insert( mapObject[m_Year][m_Month].at(i).GetWeather().GetSolar() );
        }
    } // End of FOR

    // output highest solar radiation with time
    if( data )
    {
        tempSolar = srBST.MaxValue();
        cout << "Highest solar radiation for the day: " << tempSolar << " W/m2." << fixed << setprecision(1) << endl;

        cout << "\nTime: " << fixed << setprecision(4) << endl;
        for( int i = 0; i < mapObject[m_Year][m_Month].size(); i++)
        {
            tempDay = mapObject[m_Year][m_Month].at(i).GetDate().GetDay();
            if( tempDay == m_Day )
            {
                if( mapObject[m_Year][m_Month].at(i).GetWeather().GetSolar() == tempSolar )
                {
                    cout <<  mapObject[m_Year][m_Month].at(i).GetTime() << endl;
                }
            }
        } // End of FOR
    }
    else
    {
        cout << "\nInvalid Data/No Data output" << endl;
    }
} // END OF Option5()


void MenuOption::MenuList()
{
    int option = 0;

    // Display Menu List Option
    cout << "----- [MENU] -----" << endl << endl << endl;
    cout << "[1]. The average wind speed and average ambient air temperature for a specified month and year." << endl;
    cout << "[2]. Average wind speed and average ambient air temperature for each month of a specified year." << endl;
    cout << "[3]. Total solar radiation in kWh/m2 for each month of a specified year." << endl;
    cout << "[4]. Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of a specified year." << endl;
    cout << "[5]. Display the highest Solar Radiation of an specified date." << endl;
    cout << "[6]. Exit the program " << endl << endl;

    // The program will continue to loop until user choose to exit ( select option 6 )
    while(option != 6)
    {

        // Prompt for User input Option
        cout << "" << endl;
        cout << "Enter an Menu Option Please !! " << endl;
        cin >> option;

        // Display the Menu Option Functions for the user.
        switch(option)
        {
        case 1:
        {
            Option1(); // Menu Option 1
            break;
        }

        case 2:
        {
            Option2(); // Menu Option 2
            break;
        }

        case 3:
        {
            Option3(); // Menu Option 3
            break;
        }
        case 4:
        {
            Option4(); // Menu Option 4
            break;
        }
        case 5:
        {
            Option5(); // Menu Option 5
            break;
        }
        case 6: // Program will be terminate or exit if the user input enter "6".
        {
            cout <<"----- Terminating/Exiting the Program -----" << endl;
            break;
        }
        default: // Check for invalid input of the menu option.
        {
            cout << "\nInvalid Option!!!. Please enter your option again.\n" << endl;
            //exit(0);
        }
        } // END OF SWITCH-CASE
    } // END OF WHILE
} // END OF MenuList()

