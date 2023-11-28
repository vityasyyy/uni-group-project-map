#include<iostream>
#include<vector>
#include <limits>
#include <iomanip>

using namespace std;

struct Kota{ // struct untuk kota yang akan didisplay
    string nama;
    int populasi;
    double luas;
    double densitas;
    string landmark;
};
struct Distance { // struct untuk jarak dan waktu tempuh kota
    string fromCity;
    string toCity;
    double value;
    int carTime;
    int motorcycleTime;
};

void displayCity(string cityChoice, vector<Kota> kota){ // function untuk mendisplay kota
        for(const auto &city : kota){ // for each loop untuk iterasi dari array of struct Kota
        if(city.nama == cityChoice){ // conditional, kalau kota pilihan ada di array
            cout << '\n';
            cout << "Details of " << city.nama << ":" << endl;
            cout << "Population: " << city.populasi << " jiwa" << endl;
            cout << "Area: " << city.luas << " square km" << endl;
            cout << "Density: " << city.densitas << " people per square meter" << endl;
            cout << "Landmark: " << city.landmark << endl;
            break;
        }
    }
}
int main(){
    // Array of struct kota
    vector<Kota> kota = {{"Magelang", 121526, 16.06, 0.0, "Candi Borobudur"}, 
                        {"Pekalongan", 307150, 45.25, 0.0, "Masjid Agung Al-Jami, Alun-alun Pekalongan"}, {"Salatiga", 192322, 57.36, 0.0, "Taman Nasional Gunung Merbabu"}, 
                        {"Semarang", 1653524, 373.78, 0.0, "Kota Lama, Lawang Sewu"}, {"Surakarta", 522364, 46.01,0.0, "Masjid Zayed, Kampung Batik"}, 
                        {"Tegal", 273825, 39.68, 0.0, "Kelenteng Tek Hay Kiong"}, {"Yogyakarta", 422732, 32.5, 0.0, "Malioboro, UGM, Prambanan"}};

    for (auto& city : kota) { // Untuk menghitung density
        city.densitas = static_cast<double>(city.populasi) / (city.luas * 1000);
    }

    // Array of struct untuk jarak dan waktu tempuh
    vector<Distance> distances = {
        {"Yogyakarta", "Semarang", 129.6, 159, 184},
        {"Yogyakarta", "Tegal", 278.8, 262, 356},
        {"Yogyakarta", "Pekalongan", 217.2, 222, 259},
        {"Yogyakarta", "Surakarta", 63.4, 117, 104},
        {"Yogyakarta", "Salatiga", 85.2, 131, 128},
        {"Yogyakarta", "Magelang", 43.9, 74, 65},
        {"Semarang", "Tegal", 160.1, 122, 242},
        {"Semarang", "Pekalongan", 98.5, 83, 147},
        {"Semarang", "Surakarta", 105.7, 97, 149},
        {"Semarang", "Salatiga", 50.1, 60, 62},
        {"Semarang", "Magelang", 82.5, 110, 110},
        {"Tegal", "Pekalongan", 78.6, 66, 91},
        {"Tegal", "Surakarta", 255.9, 202, 372},
        {"Tegal", "Salatiga", 200.3, 161, 295},
        {"Tegal", "Magelang", 232.8, 211, 289},
        {"Pekalongan", "Surakarta", 194.1, 163, 278},
        {"Pekalongan", "Salatiga", 138.5, 121, 200},
        {"Pekalongan", "Magelang", 170.9, 174, 193},
        {"Surakarta", "Salatiga", 55.4, 71, 77},
        {"Surakarta", "Magelang", 98.5, 148, 139},
        {"Salatiga", "Magelang", 49.4, 81, 66}
    };
    
    string cityChoice;
    cout << "1. Semarang\n" << "2. Yogyakarta\n" << "3. Tegal\n" << "4. Pekalongan \n" << "5. Magelang\n" << "6. Surakarta\n" << "7. Salatiga\n";
    cout << "Enter the city you wanna know: ";
    cin >> cityChoice;

    displayCity(cityChoice, kota); 


    char visitOrNo;
    cout << '\n';
    cout << "Do you want to go to that city(y/n): ";
    cin >> visitOrNo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Menghilangkan input buffer
    
    if(tolower(visitOrNo)!='y'){
        cout << "You chose not to visit " << cityChoice << ". Have a nice day!!" << '\n';
    }
    else{
        char transportMode;
        cout << '\n';
        cout << "Do you use a car or a motorcycle(c/m): ";
        cin >> transportMode;

        int hour, minute;
        cout << '\n';
        cout << "Enter your current time(hours minute):";
        cin >> hour >> minute;

        string currentCity;
        cout << '\n';
        cout << "Enter your current city: ";
        cin >> currentCity;

        double distance = 0.0; 

        for(const auto &dist : distances){ // For each loop untuk iterasi setiap element yang ada di array of struct distance
            
            // Jika kondisi terpenuhi, program akan dijalankan
            if((dist.fromCity == currentCity && dist.toCity == cityChoice &&transportMode == 'c' || dist.fromCity == cityChoice && dist.toCity == currentCity &&transportMode == 'c')){
                distance = dist.value;
                int minutePlus = dist.carTime;
                minute += minutePlus;
                hour += minute / 60;
                minute %= 60;
                cout << "The distance is " << distance << "km." << '\n';
                cout << "You'll arrive at roughly " << setw(2) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute << '\n';
                break;
            }

            else if((dist.fromCity == currentCity && dist.toCity == cityChoice &&transportMode == 'm' || dist.fromCity == cityChoice && dist.toCity == currentCity &&transportMode == 'm')){
                distance = dist.value;
                int minutePlus = dist.motorcycleTime;
                minute += minutePlus;
                hour += minute / 60;
                minute %= 60;
                cout << "The distance is " << distance << "km.";
                cout << "You'll arrive at roughly " << setw(2) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute << '\n';
                break;
            }
        }
    }
}
