#ifndef POSTCODEDEF
#define POSTCODEDEF
#include <set>
#include <vector>
#include <algorithm>
enum PostCode{OK, LOAD, DESTROY, CLOSE,ERR};
struct coord {
	int x;
	int y;
	coord operator+(coord another) {
		coord res;
		res.x=x+another.x;
		res.y=y+another.y;
		return res;
	}
	coord operator-(coord another) {
		coord res;
		res.x=x-another.x;
		res.y=y-another.y;
		return res;
	}
	coord operator/(int another) {
		coord res;
		res.x=x/another;
		res.y=y/another;
		return res;
	}
};
struct allContr {
	coord LBtn;
	coord RBtn;
	coord MPos;
	std::vector<int> keys;
	std::vector<int> chars;
	bool isContain(int code) {
		return std::find(keys.begin(),keys.end(),code)!=keys.end();
	}
	bool isClk(coord c) {
		return c.x>0 && c.y>0;
	}
	void resetKeys() {
		keys.erase(keys.begin(),keys.end());
		chars.erase(chars.begin(),chars.end());
	}
};
#endif
