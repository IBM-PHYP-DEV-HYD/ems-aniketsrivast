#include "HelperClass.H"

bool HelperClass::validateDOJ(string DOBParam, string DOJParam){
    // Extract parts using substr + stoi
    int sDobDay   = stoi(DOBParam.substr(0, 2));
    int sDobMonth = stoi(DOBParam.substr(3, 2));
    int sDobYear  = stoi(DOBParam.substr(6, 4));

    int sDojDay   = stoi(DOJParam.substr(0, 2));
    int sDojMonth = stoi(DOJParam.substr(3, 2));
    int sDojYear  = stoi(DOJParam.substr(6, 4));

    int sAge = sDojYear - sDobYear;

    // If they haven't reached birthday yet in that year → subtract one
    if (sDojMonth < sDobMonth || (sDojMonth == sDobMonth && sDojDay < sDobDay)) {
        sAge--;
    }

    return sAge >= 18;
}

bool HelperClass::validateName(string &nameParam){
        if(nameParam.empty()){
            return false;
        }
        if (nameParam.length() > 22) {
            nameParam = nameParam.substr(0, 22);
        }
        return true;
}

bool HelperClass::isValidDateFormat(const string& dateParam) {
    bool sFlag = true;
    if (dateParam.length() != 10){
        sFlag = false;
    }
    if (dateParam[2] != '-' || dateParam[5] != '-'){
        sFlag = false;
    }
    for (int i = 0; i < dateParam.length(); ++i) {
        if (i == 2 || i == 5){
            continue;  // skip dashes
        }
        if (!isdigit(dateParam[i])){
            sFlag = false;
        }
    }
    return sFlag;
}

// Read integer by ignoring any spaces or newlines present
int HelperClass::readIntSafely() {
    int sInput;
    while (!(cin >> sInput)) {
        cout << "Invalid input. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return sInput;
}

// Pause buffer in mid
void HelperClass::pauseForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}