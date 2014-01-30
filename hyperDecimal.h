#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string.h>

using namespace std;

const long long unsigned HOLDERMAX = 1000000000;
const long long unsigned MULTMAX = 2000000000;

class hyperDecimal{
public:
	hyperDecimal(){
		data.push_back(1);
	}
	virtual ~hyperDecimal(){}
	hyperDecimal& operator*=(const long long unsigned &rhs){
		long long unsigned holderCarry = 0;
		if(MULTMAX < rhs) return *this;
		for(unsigned it = 0; it < data.size(); it++){
			data[it] *= rhs;
			data[it] += holderCarry;
			holderCarry = 0;
			while(data[it] >= HOLDERMAX){
				data[it] -= HOLDERMAX;
				holderCarry++;
			}
		}
		while(holderCarry != 0){
			data.push_back(holderCarry);
			holderCarry = 0;
			unsigned i = data.size()-1;
			while(data[i] >= HOLDERMAX){
				data[i] -= HOLDERMAX;
				holderCarry++;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& stream, const hyperDecimal& rhs){
		int size = rhs.data.size();
		stream << rhs.data[size-1];
		if (size > 1){
			for(unsigned it = (size - 2); it > 0; it--){
				stream << setfill('0') << setw(9) << rhs.data[it];
			}
		}
		if(size != 1)
			stream << setfill('0') << setw(9) << rhs.data[0];
		return stream;
	}
private:
	vector<long long unsigned> data;
};