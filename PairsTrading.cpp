#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include <string>

using namespace std;

struct StockRecord {
public:
	StockRecord(
		string date,
		double open,
		double high,
		double low,
		double close,
		double adjClose,
		int vol
	) {
		newDate = date;
		newOpen = open;
		newHigh = high;
		newLow = low;
		newClose = close;
		newAdjClose = adjClose;
		newVol = vol;
	}

	void display() {
		cout << "\nDate: " << newDate << endl;
		cout << "Open: " << newOpen << endl;
		cout << "High: " << newHigh << endl;
		cout << "Low: " << newLow << endl;
		cout << "Close: " << newClose << endl;
		cout << "Adj Close: " << newAdjClose << endl;
		cout << "volume: " << newVol;
	}


	string newDate;
	double newOpen;
	double newHigh;
	double newLow;
	double newClose;
	double newAdjClose;
	int newVol;

};
void displayStockData(vector<StockRecord>& stocks) {

	for (auto stock : stocks) {
		stock.display();
		cout << "\n--------------";
	}
}

int main() {

	ifstream inputFile1;
	inputFile1.open("NFLX.csv");
	string line1 = "";
	vector<StockRecord> NFLX;

	while (getline(inputFile1, line1)) {
		stringstream inputString(line1);

		string date;
		double open;
		double high;
		double low;
		double close;
		double adjClose;
		int vol;
		string tempString;

		getline(inputString, date, ',');
		getline(inputString, tempString, ',');
		open = atof(tempString.c_str());
		getline(inputString, tempString, ',');
		high = atof(tempString.c_str());
		getline(inputString, tempString, ',');
		low = atof(tempString.c_str());
		getline(inputString, tempString, ',');
		close = atof(tempString.c_str());
		getline(inputString, tempString, ',');
		adjClose = atof(tempString.c_str());
		getline(inputString, tempString, ',');
		vol = atoi(tempString.c_str());

		StockRecord stock(date, open, high, low, close, adjClose, vol); //obj
		NFLX.push_back(stock);
		line1 = "";
	}

	//Start of Netflix Data

	for (int i = 0; i < NFLX.size() - 1; i++) {
		for (int j = 0; j < NFLX.size() - 1; j++) {
			if (NFLX[j].newAdjClose > NFLX[j + 1].newAdjClose) {
				int temp = NFLX[j].newAdjClose; //sorting vector for future calculations 
				NFLX[j].newAdjClose = NFLX[j + 1].newAdjClose;
				NFLX[j + 1].newAdjClose = temp;
			}
		}
	}

	double sum_NFLX = 0;
	for (int i = 0; i < NFLX.size(); i++) {
		sum_NFLX += (NFLX[i].newAdjClose);
	}

	double max_NFLX = NFLX[0].newAdjClose;
	for (int i = 0; i < NFLX.size(); i++) {
		if (NFLX[i].newAdjClose > max_NFLX) {
			max_NFLX = NFLX[i].newAdjClose;
		}
	}
	double min_NFLX = NFLX[0].newAdjClose;
	for (int i = 0; i < NFLX.size(); i++) {
		if (NFLX[i].newAdjClose < min_NFLX) {
			min_NFLX = NFLX[i].newAdjClose;
		}
	}

	cout << "\nStock 1: Netflix" << "\n-----------------\n";
	cout << "maximum value: " << max_NFLX;
	cout << endl;
	double mean_NFLX = sum_NFLX / NFLX.size();
	cout << "average: " << mean_NFLX;
	cout << "\nminimum value: " << min_NFLX;
	cout << "\nrange: " << max_NFLX - min_NFLX;

	double sqDiff_NFLX = 0;
	for (int i = 0; i < NFLX.size(); i++) {
		sqDiff_NFLX += pow((NFLX[i].newAdjClose - mean_NFLX), 2);
	}

	cout << "\nvariance: " << sqDiff_NFLX / NFLX.size() - 1;
	double standardDeviation_NFLX = sqrt(sqDiff_NFLX / NFLX.size()) - 1;
	cout << "\nstandard deviation: " << standardDeviation_NFLX << endl;
	cout << "IQR: ";

	//IQR
	double q3_NFLX = (NFLX.size() + 1) * .75;
	double q1_NFLX = (NFLX.size() + 1) * .25;
	double IQR_NFLX = NFLX[q3_NFLX].newAdjClose - NFLX[q1_NFLX].newAdjClose;
	cout << IQR_NFLX << endl << endl;


	//Start of Paramount Data
	ifstream inputFile2;
	inputFile2.open("PARAA.csv");
	string line2 = "";
	vector<StockRecord> PARAA;

	while (getline(inputFile2, line2)) {
		stringstream inputString(line2);

		string date;
		double open;
		double high;
		double low;
		double close;
		double adjClose;
		int vol;
		string tempString;

		getline(inputString, date, ',');
		getline(inputString, tempString, ',');
		open = atof(tempString.c_str());
		getline(inputString, tempString, ',');
		high = atof(tempString.c_str());
		getline(inputString, tempString, ',');
		low = atof(tempString.c_str());
		getline(inputString, tempString, ',');
		close = atof(tempString.c_str());
		getline(inputString, tempString, ',');
		adjClose = atof(tempString.c_str());
		getline(inputString, tempString, ',');
		vol = atoi(tempString.c_str());

		StockRecord stock(date, open, high, low, close, adjClose, vol); //obj
		PARAA.push_back(stock);
		line2 = "";
	}


	for (int i = 0; i < PARAA.size() - 1; i++) {
		for (int j = 0; j < PARAA.size() - 1; j++) {
			if (PARAA[j].newAdjClose > PARAA[j + 1].newAdjClose) {
				int temp = PARAA[j].newAdjClose; //sorting vector for future calculations 
				PARAA[j].newAdjClose = PARAA[j + 1].newAdjClose;
				PARAA[j + 1].newAdjClose = temp;
			}
		}
	}

	double sum_PARAA = 0;
	for (int i = 0; i < PARAA.size(); i++) {
		sum_PARAA += (PARAA[i].newAdjClose);
	}

	double max_PARAA = PARAA[0].newAdjClose;
	for (int i = 0; i < PARAA.size(); i++) {
		if (PARAA[i].newAdjClose > max_PARAA) {
			max_PARAA = PARAA[i].newAdjClose;
		}
	}
	double min_PARAA = PARAA[0].newAdjClose;
	for (int i = 0; i < PARAA.size(); i++) {
		if (PARAA[i].newAdjClose < min_PARAA) {
			min_PARAA = PARAA[i].newAdjClose;
		}
	}

	cout << "\nStock 2: Paramount" << "\n-----------------\n";
	cout << "maximum value: " << max_PARAA;
	cout << endl;
	double mean_PARAA = sum_PARAA / PARAA.size();
	cout << "average: " << mean_PARAA;
	cout << "\nminimum value: " << min_PARAA;
	cout << "\nrange: " << max_PARAA - min_PARAA;

	double sqDiff_PARAA = 0;
	for (int i = 0; i < PARAA.size(); i++) {
		sqDiff_PARAA += pow((PARAA[i].newAdjClose - mean_PARAA), 2);
	}

	cout << "\nvariance: " << sqDiff_PARAA / PARAA.size() - 1;
	double standardDeviation_PARAA = sqrt(sqDiff_PARAA / PARAA.size()) - 1;
	cout << "\nstandard deviation: " << standardDeviation_PARAA << endl;
	cout << "IQR: ";

	//IQR
	double q3_PARAA = (PARAA.size() + 1) * .75;
	double q1_PARAA = (PARAA.size() + 1) * .25;
	double IQR_PARAA = PARAA[q3_PARAA].newAdjClose - PARAA[q1_PARAA].newAdjClose;
	cout << IQR_PARAA << endl;
	//correlation

	double sum_PARAA_NFLX = sum_NFLX * sum_PARAA;
	cout << endl << sum_PARAA_NFLX;
	
	return 0;
}


