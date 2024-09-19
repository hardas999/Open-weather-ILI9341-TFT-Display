//  Use the OpenWeather library: https://github.com/Bodmer/OpenWeather

//  The weather icons and fonts are in the sketch data folder, press Ctrl+K
//  to view.


//            >>>       IMPORTANT TO PREVENT CRASHES      <<<
//>>>>>>  Set SPIFFS to at least 1.5Mbytes before uploading files  <<<<<<


//                >>>           DON'T FORGET THIS             <<<
//  Upload the fonts and icons to SPIFFS using the "Tools"  "ESP32 Sketch Data Upload"
//  or "ESP8266 Sketch Data Upload" menu option in the IDE.
//  To add this option follow instructions here for the ESP8266:
//  https://github.com/esp8266/arduino-esp8266fs-plugin
//  To add this option follow instructions here for the ESP32:
//  https://github.com/me-no-dev/arduino-esp32fs-plugin

//  Close the IDE and open again to see the new menu option.

// You can change the number of hours and days for the forecast in the
// "User_Setup.h" file inside the OpenWeather library folder.
// By default this is 6 hours (can be up to 48) and 5 days
// (can be up to 8 days = today plus 7 days). This sketch requires
// at least 5 days of forecast. Forecast hours can be set to 1 as
// the hourly forecast data is not used in this sketch.

//////////////////////////////
// Setttings defined below

#define TIMEZONE euCET // See NTP_Time.h tab for other "Zone references", UK, usMT etc

// Update every 15 minutes, up to 1000 request per day are free (viz average of ~40 per hour)
const int UPDATE_INTERVAL_SECS = 10 * 60UL; // 15 minutes

// Pins for the TFT interface are defined in the User_Config.h file inside the TFT_eSPI library

// For units use "metric" or "imperial"
const String units = "metric";

// Sign up for a key and read API configuration info here:
// https://openweathermap.org/, change x's to your API key
const String api_key = "9aa098b4e0ee20f3e839a96648d6fd89";

// Set the forecast longitude and latitude to at least 4 decimal places
const String latitude =  "54.9092"; // Vilijampolė
const String longitude = "23.8897"; // Vilijampolė

//const String latitude =  "54.8265"; // Mastaičiai
//const String longitude = "23.8221"; // Mastaičiai

// For language codes see https://openweathermap.org/current#multi
const String language = "lt"; // Default language = en = English

// Short day of week abbreviations used in 4 day forecast (change to your language)
const String shortDOW [8] = {"???", "SEKM", "PIRM", "ANTR", "TREC", "KETV", "PENK", "SEST"};

// Change the labels to your language here:
const char sunStr[]        = "Saule";
const char cloudStr[]      = "Debesuota";
const char humidityStr[]   = "Dregme";
const String moonPhase [8] = {"Jaunatis", "Jaunatis", "Priespilnis", "Priespilnis", "Pilnatis", "Pilnatis", "Delcia", "Delcia"};

// End of user settings
//////////////////////////////
