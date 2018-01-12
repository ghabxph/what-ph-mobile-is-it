/**
 * Copyright 2018 ghabxph(c)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @author  ghabxph <ghabxph.official@gmail.com>
 * @version v0.0.1
 * @since   2018.01.13
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

#define GLOBE       &_GLOBE;
#define SMART       &_SMART;
#define SUN         &_SUN;
#define ABS_GLOBE   &_ABS_GLOBE;
#define EXPRESS     &_EXPRESS;
#define NEXT        &_NEXT;

string _GLOBE      = "Globe";
string _SMART      = "Smart";
string _SUN        = "Sun Cellular";
string _ABS_GLOBE  = "ABS-CBN / Globe";
string _EXPRESS    = "Express Telecom";
string _NEXT       = "Next Mobile";

/// ----------------------- ///
/// Prototypes              ///
/// ----------------------- ///
/**/ string getInput();     ///
/// ----------------------- ///

int main() {
    /// ------------------------------- ///
    /// Initialization                  ///
    /// ------------------------------- ///
    /**/ string input;                  ///
    /**/ string *network;               ///
    /**/ map<string, string*> prefixes; ///
    /// ------------------------------- ///

    /// 090X prefix
    prefixes["0905"] = GLOBE;
    prefixes["0906"] = GLOBE;
    prefixes["0907"] = SMART;
    prefixes["0908"] = SMART;
    prefixes["0909"] = SMART;

    /// 091X prefix
    prefixes["0912"] = SMART;
    prefixes["0915"] = GLOBE;
    prefixes["0916"] = GLOBE;
    prefixes["0917"] = GLOBE;
    prefixes["0918"] = SMART;
    prefixes["0919"] = SMART;
    prefixes["0910"] = SMART;

    /// 092X prefix
    prefixes["0921"] = SMART;
    prefixes["0922"] = SUN;
    prefixes["0923"] = SUN;
    prefixes["0925"] = SUN;
    prefixes["0926"] = GLOBE;
    prefixes["0927"] = GLOBE;
    prefixes["0928"] = SMART;
    prefixes["0929"] = SMART;
    prefixes["0920"] = SMART;

    /// 093X prefix
    prefixes["0932"] = SUN;
    prefixes["0933"] = SUN;
    prefixes["0935"] = GLOBE;
    prefixes["0936"] = GLOBE;
    prefixes["0937"] = ABS_GLOBE;
    prefixes["0938"] = SMART;
    prefixes["0939"] = SMART;
    prefixes["0930"] = SMART;

    /// 094X prefix
    prefixes["0942"] = SUN;
    prefixes["0943"] = SUN;
    prefixes["0945"] = GLOBE;
    prefixes["0946"] = SMART;
    prefixes["0947"] = SMART;
    prefixes["0948"] = SMART;
    prefixes["0949"] = SMART;

    /// 095X prefix
    prefixes["0955"] = GLOBE;
    prefixes["0956"] = GLOBE;
    prefixes["0950"] = SMART;

    /// 097X prefix
    prefixes["0973"] = EXPRESS;
    prefixes["0974"] = EXPRESS;
    prefixes["0975"] = GLOBE;
    prefixes["0977"] = GLOBE;
    prefixes["0978"] = NEXT;
    prefixes["0979"] = NEXT;

    /// 098X prefix
    prefixes["0979"] = SMART;

    /// 099X prefix
    prefixes["0995"] = GLOBE;
    prefixes["0996"] = GLOBE;
    prefixes["0997"] = GLOBE;
    prefixes["0998"] = SMART;
    prefixes["0999"] = SMART;

    do {
        input = getInput();
        network = prefixes[input];
        cout << "Network: " << ((network == nullptr) ? "Unknown" : *network) << endl;
    } while (stoi(input) > 0);

    return 0;
}

string getInput() {
    /// ------------------------------ ///
    /// Initialization                 ///
    /// ------------------------------ ///
    /**/ string input;                 ///
    /**/ bool inputIsInvalid;          ///
    /// ------------------------------ ///

    inputIsInvalid = true;

    do {
        cout << "Enter 4 digit prefix (enter 0 to exit): ";
        cin >> input;
        try {
            return "0" + to_string(stoi(input.c_str()));
        } catch (const std::invalid_argument& ia) {
            cout << "Please enter a number!" << endl;
        }
    } while (true);
}
