
#include <iostream>
#include <algorithm>
using namespace std;

struct Environment {
    int temp, humid, pollution;
};

int main() {
    Environment a[50];
    int n, choice;

    cout << "Enter number of entries: ";
    cin >> n;

    if (n < 1 || n > 50) {
        cout << "Invalid number of entries";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter temperature, humidity and pollution: ";
        cin >> a[i].temp >> a[i].humid >> a[i].pollution;
    }

    do {
        cout << "\n1. Display Data";
        cout << "\n2. Average";
        cout << "\n3. Maximum and Minimum";
        cout << "\n4. Check Safe Values";
        cout << "\n5. Sort by Temperature";
        cout << "\n6. Impact Analysis";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "\nTemp\tHumidity\tPollution\n";
            for (int i = 0; i < n; i++) {
                cout << a[i].temp << "\t"
                     << a[i].humid << "\t\t"
                     << a[i].pollution << endl;
            }
            break;

        case 2: {
            float t = 0, h = 0, p = 0;

            for (int i = 0; i < n; i++) {
                t += a[i].temp;
                h += a[i].humid;
                p += a[i].pollution;
            }

            cout << "Average Temperature: " << t/n << endl;
            cout << "Average Humidity: " << h/n << endl;
            cout << "Average Pollution: " << p/n << endl;
            break;
        }

        case 3: {
            int maxt = a[0].temp, mint = a[0].temp;
            int maxh = a[0].humid, minh = a[0].humid;
            int maxp = a[0].pollution, minp = a[0].pollution;

            for (int i = 1; i < n; i++) {
                maxt = max(maxt, a[i].temp);
                mint = min(mint, a[i].temp);

                maxh = max(maxh, a[i].humid);
                minh = min(minh, a[i].humid);

                maxp = max(maxp, a[i].pollution);
                minp = min(minp, a[i].pollution);
            }

            cout << "Max Temperature: " << maxt << endl;
            cout << "Min Temperature: " << mint << endl;
            cout << "Max Humidity: " << maxh << endl;
            cout << "Min Humidity: " << minh << endl;
            cout << "Max Pollution: " << maxp << endl;
            cout << "Min Pollution: " << minp << endl;
            break;
        }

        case 4: {
            int maxt = a[0].temp;
            int maxh = a[0].humid;
            int maxp = a[0].pollution;

            for (int i = 1; i < n; i++) {
                maxt = max(maxt, a[i].temp);
                maxh = max(maxh, a[i].humid);
                maxp = max(maxp, a[i].pollution);
            }

            if (maxt > 45)
                cout << "Unsafe Temperature\n";
            else
                cout << "Safe Temperature\n";

            if (maxh > 40)
                cout << "High Humidity\n";
            else
                cout << "Normal Humidity\n";

            if (maxp > 300)
                cout << "High Pollution\n";
            else
                cout << "Normal Pollution\n";

            break;
        }

        case 5:
            sort(a, a + n, [](Environment x, Environment y) {
                return x.temp < y.temp;
            });

            cout << "Data sorted by temperature:\n";
            for (int i = 0; i < n; i++) {
                cout << a[i].temp << "\t"
                     << a[i].humid << "\t"
                     << a[i].pollution << endl;
            }
            break;

        case 6: {
            int maxt = a[0].temp;
            int maxh = a[0].humid;
            int maxp = a[0].pollution;

            for (int i = 1; i < n; i++) {
                maxt = max(maxt, a[i].temp);
                maxh = max(maxh, a[i].humid);
                maxp = max(maxp, a[i].pollution);
            }

            if (maxt > 35 && maxh > 30)
                cout << "Heat and humidity may cause discomfort.\n";

            if (maxp > 200)
                cout << "Pollution may cause health problems.\n";

            if (maxt <= 35 && maxp <= 200)
                cout << "Environmental conditions are normal.\n";

            cout << "Impact analysis completed.\n";
            break;
        }

        case 7:
            cout << "Exiting program.";
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 7);

    return 0;
}
