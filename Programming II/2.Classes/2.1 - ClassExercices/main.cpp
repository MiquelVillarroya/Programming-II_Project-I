#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void ex1();
void ex2();
void ex3();
void ex4();
void ex5();



int main() {

	cout << "Ex1" << endl;
	ex1();
	cout << endl;

	cout << "Ex2" << endl;
	ex2();
	cout << endl;

	cout << "Ex3" << endl;
	ex3();
	cout << endl;

	cout << "Ex4" << endl;
	ex4();
	cout << endl;

	cout << "Ex5" << endl;
	ex5();
	cout << endl;
}

class Pixel {
private:
	int	red, green, blue;

public:
	Pixel () {
		red = 0;
		green = 0;
		blue = 0;
	}

	Pixel(int r, int g, int b) {
		red = r;
		green = g;
		blue = b;
	}

	int getR(){
		return red;
	}
	int getG(){
		return green;
	}
	int getB() {
		return blue;
	}

	Pixel mix (Pixel mix) {
		Pixel mixed;
		mixed.red = (red + mix.red) / 2;
		mixed.green = (green + mix.green) / 2;
		mixed.blue = (blue + mix.blue) / 2;
		return mixed;
	}
};

void ex1() {

	Pixel black;
	Pixel blue (0, 0, 255);
	Pixel red (255, 0, 0);
	Pixel mixed = red.mix(blue);

	cout << black.getR() << " " << black.getG() << " " << black.getB() << endl;
	cout << mixed.getR() << " " << mixed.getG() << " " << mixed.getB() << endl;
}

class Clock {
private:
	 unsigned int hours, minutes, seconds;

public:
	Clock() {
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	Clock(unsigned int h, unsigned int min, unsigned int sec) {
		hours = h;
		minutes = min;
		seconds = sec;
	}

	unsigned int getH() {
		return hours;
	}
	unsigned int getMin() {
		return seconds;
	}
	unsigned int getSec() {
		return seconds;
	}

	void sameClock(Clock clock2) {
		if (clock2.hours != hours || clock2.minutes != minutes || clock2.seconds != seconds) {
			cout << "The clocks show different times!" << endl;
			return;
		}

		cout << "The clocks show the same time ^^" << endl;
	}
	void firstClock(Clock clock2) {
		unsigned int clocktotal = hours * 3600 + minutes * 60 + seconds;
		unsigned int clocktotal2 = clock2.hours * 3600 + clock2.minutes * 60 + clock2.seconds;

		if (clocktotal2 < clocktotal) {
			cout << "The second clock goes first!" << endl;
		}
		else if (clocktotal2 == clocktotal) {
			cout << "The clock show the same time!" << endl;
		}
		else {
			cout << "The second clock goes last!" << endl;
		}
	}

	void setTime(unsigned int h, unsigned int min, unsigned int sec) {
		hours = h;
		minutes = min;
		seconds = sec;
	}

	void printTime() {
		cout << hours << ":" << minutes << ":" << seconds << endl;
	}

};

void ex2() {
	Clock clock1;
	Clock clock2(23, 58, 59);
	clock1.setTime(10,10,10);
	clock1.printTime();
	clock1.sameClock(clock2);
	clock1.firstClock(clock2);

	clock2.setTime(10, 10, 10);
	clock1.sameClock(clock2);
	clock1.firstClock(clock2);

	clock2.setTime(10, 10, 9);
	clock1.firstClock(clock2);

}

class Vec3 {
private:

public:
	float x, y, z;

	Vec3() : x(0), y(0), z(0) {
	}
	Vec3(float x, float y , float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vec3(const Vec3& vec) {
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
	}

	void getVec() {
		cout << x << " " << y << " " << z << endl;
	}

	float length() {
		float length = sqrtf(x * x + y * y + z * z);
		return length;
	}
	Vec3 inverse() {
		Vec3 vec;
		vec.x = -x;
		vec.y = -y;
		vec.z = -z;
		return vec;
	}
};

float dot(Vec3 vec1, Vec3 vec2) {
	
	float result = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	return result;
}

void ex3() {
	
	Vec3 vec1;
	vec1.getVec();
	Vec3 vec2 (1,2,3);
	vec2.getVec();
	Vec3 vec3(vec2);
	vec3.getVec();
	cout << vec2.length() << endl;
	Vec3 vec2inv = vec2.inverse();
	vec2inv.getVec();
	cout << dot(vec2, vec2inv) << endl;
}

class HighscoreEntry {
private:
	const char* name;
	unsigned int score;

public:
	HighscoreEntry() : name("Unknown"), score(0000) {
	}

	HighscoreEntry(const char* name, unsigned int score){
		this->name = name;
		this->score = score;
	}

	HighscoreEntry(HighscoreEntry& user) {
		
		this->name = user.name;
		this->score = user.score;
	}

	const char * toString() {
		return "";
	}

	int sameAs(HighscoreEntry hs) {
		
		if (hs.name != name || score != hs.score) {
			return 0;
		}
		
		return 1;
	}
};

void ex4() {

	HighscoreEntry h1("Homer", 9999);
	HighscoreEntry h2("Bart", 7777);
	HighscoreEntry h3;
	HighscoreEntry h4(h2);

	const char* str = h1.toString();
	cout << "h1: " << str << endl;
	cout << "h2: " << h2.toString() << endl;
	cout << "h3: " << h3.toString() << endl;

	if (h2.sameAs(h4)) {
		cout << "h2 and h4 are the same" << endl;
	}
	else {
		cout << "h2 and h4 are not the same" << endl;
	}

}

class Module {
private:
	const char* name;
	unsigned int iterations;

public:
	Module(const char* initialize, unsigned int numIterations) {
		this->name = initialize;
		this->iterations = numIterations;
	}
	void methodUpdate(unsigned int currentIteration) {
		if (currentIteration < iterations) {
			cout << name << endl; 
		}
	}

};

void ex5() {

	Module* modules[4];
	modules[0] = new Module("Input", 5);
	modules[1] = new Module("Render", 7);
	modules[2] = new Module("Logic", 10);
	modules[3] = new Module("Sasel", 3);


	
	for (int i = 0; i < 10; ++i) {
		cout << "--- Iteration " << i << endl;
		for (int j = 0; j < 4; ++j) {
			modules[j]->methodUpdate(i);
		}
	}

	delete modules[0];
	delete modules[1];
	delete modules[2];
	delete modules[3];

}
