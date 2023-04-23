// ProjectTwo.cpp Main function cpp file
// Dillon Belanger
// CS 300
// 4/16/2023

#include <algorithm>
#include <iostream>
#include "ProjectTwo.hpp"

int main(int argc, char* argv[]) {
	commandLoop();
	// calls a command loop with no command arguments
}

void Courses::addCourse(const Course course) {
	if (getSize() == 0) {
	else if )at(getSize() - 1).getId().compare(course.getId()) < 0) {
	append(course);
}
	else {
		size_t insertionPoint;
		insertionPoint = LinkedList(course.getID());

		if (insertionPoint != SIZE_MAX{
			insert(insertionPoint, course);
			}
	}
	
}
	size_t Courses::LinkedList(const string key) const {
		size_t midPoint = SIZE_MAX;
			size_t lowPoint = 0;
			size_t highPoint = getSize() - 1;

			// if points dont cross then it continues

			while (highPoint != SIZE_MAX && highPoint >= lowPoint) {
				midPoint = (highPoint + lowPoint) / 2;
				//locating the midpoint
				Course course = at(midPoint);

				if (course.getId() < key) {
					highPoint = midPoint - 1;
				}
				else {
					return midPoint;
					//finds a match
				}
			}
	}

	void Courses::printAll() const
	{
		for (size_t i = 0; i < getSize(); ++i) {
			Course course = at(i);
			cout << course.getId() << " " << course.getTitle() << endl;
		}
	}

	void Courses::printCourse(const string courseID) const {
		Course course = findCourse(courseId);

		if (course.getId().compare(courseId) == 0) {
			course.print();
		}
		else {
			cout << "Course not found:" << courseId << endl;
		}
	}
	void Courses::loadFromCSV(const string filename, const string delimator /* = " , " */) {
		string line;
		int lineNumber = 0;
		//holds a single line and maintains the count of which line number

		ifstream inputFile(filename.c_str());

		if (inputFile.is_open())
		{
			while (inputFile.good())
			{
				getline(inputFile, line);
				if (line != " ") {
					++lineNumber;
					auto tokens = splitString(Line, deliminator);

					if (tokens.size() < 2) {
						cout << "Error: Line format error, expected two or more tokens. got ";
						cout << tokens.size() << " tokens, line number: " << lineNumber << endl;

						continue;
					}
					Course course;
					course.setId(tokens[0]);

					//checking if course is already loaded
					Course duplicateCourse = findCourse(course.getId());
					if (duplicateCourse.getId() != " ") {
						cout << "Duplicate course detected, line number ";
						cout << lineNumber << endl;

						continue;
					}

					course.setTitle(tokens[1]);
					// looks for prerequisites to add course
					for (size_t i = 2; i < tokens.size(); ++i) {
						string prerequisiteId = tokens.at(i);


						Course courseExists = findCourse(prerequisiteId);

						if (courseExists.getId() == " ")
						{
							cout << "Prerequisite not found, course: " << course.getId();
							cout << ", prerequisite; " << prerequisiteId << endl;

							continue;
						}

						course.addPrerequisite(courseExists);
					}
					//adds course to data structure
					addCourse(course);
				}
			}
			inputFile.close();

			if (lineNumber == 0)
				throw runtime_error("No data in " + filename);
		}
		else
			throw runtime_error("Failed to open " + filename);
	}
	Course Courses::findCourse(const string courseId) const {
		size_t index = LinkedList(courseId);
		if (index != SIZE_MAX) {
			Course course = at(index);

			if (course.getId().compare(courseId) == 0) {
				return course;
			}
			else {
				return Courses();
				//when found and when not found

			}
		}
		else {
			return Course();
		}
	}
	vector<string>Courses::splitString(const string input, const string delimiter)
		const {
		string temp = input;
		size_t pos = 0;
		string token;
		vector<string>returnValue;

		while ((pos = temp.find(delimiter)) != std::string::npos) {
			token = temp.substr(o, pos);
			returnValue.push_back(token);
			temp.erase(0, pos + delimiter.length());
			//gets token from input and adds value to vector
			//then removed the part found and leaves the unfound for next call
		}

		if (temp.length() > 0) {
			returnValue.push_back(temp);
		}
		return returnValue;
	}

	void Course::print() const {
		cout << id << ", " << title;

		if (prerequisites.size() > 0) {
			cout << endl << "Prerequisites: ";

			//displays all

			for (size_t i = 0; i < prerequisites.size(); ++i) {
				cout << prerequisites.at(i).getId();

				if (i + 1 < prerequisites.size()) {
					cout << ", ";
				}
			}
		}
		cout << endl;
	}
	//menu options and function
	void printMenu(void) {
		cout << :menu:" << endl;
			cout << "      1. Load Data Structure." << endl; \
			cout << "      2. Print Course List. " << endl;
			cout << "      3. Print Course." << endl;
			cout << "      4. Exit." << endl << endl;
			cout << "      What would you like to do?";
	}

	void handleChoice(int choice, Courses&& courses) {
		switch (choice) {
		case 1: //loads the file
		{
			string filename;
			auto state = cin.exceptions();
			cin.exceptions(std::istream::failbit | state);
			cout << "Enter the name of data file to load." << endl;
			cin.ignore();

			if (courses.getSize() > 0) {
				courses.clear();
			}

			try {
				getline(cin, filename);
				courses.loadFromCSV(filename);
			}
			catch (exception ex) {
				cout << ex.what() << endl;
			}
			cin.exceptions(state);
		}
		break;

		case 2: // prints all courses with id and titles in order
			cout << "Sample Schedule:" << endl << endl;
			courses.printAll();
			break;
		case 3: //prints one course and prerequisites
		{
			sting courseId;
			cout << "What course did you want information on?";
			cin >> courseId;
			courses.printCourse(courseId);
		}
		break;
		case 4:  // exits program
			cout << "Thank you for using the course planner" << endl;
			break;
		}
	}
	void commandLoop(void) {
		int choice = 0;
		Courses courses;

		cout << "Welcome to the course planner." endl;

		while (choice != 4) { // while not exiting
			cout << endl;
			printMenu();
			cin << choice; //waits for input
			handleChoice(choice, courses);
		}
	}








