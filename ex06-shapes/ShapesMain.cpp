#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

#include <Shape.h>
#include <Circle.h>
#include <Polygon.h>
#include <Transformation.h>
#include <ShapeStack.h>
#include <Group.h>

using namespace ds_course;
using namespace std;

// to generate all function declarations from class use CTRL+SHIFT+D

int main() {
    ShapeStack stack;
    string Line;

    while (getline(cin, Line)) {
        // parse by space
        istringstream iss(Line);
        vector<string> tokens{istream_iterator<string>{iss},
                              istream_iterator<string>{}};

        // start processing
        string cmd = tokens[0];

        // POLYGON #FFFFF 4
        if (cmd == "POLYGON" && tokens.size() == 3) {
            string color = tokens[1];
            int n = stoi(tokens[2]);
            stack.push(new Polygon(color, n));
        // CIRCLE #BC002D
        } else if (cmd == "CIRCLE" && tokens.size() == 2) {
            string color = tokens[1];
            stack.push(new Circle(color));
        } else if (cmd == "TRANSF" && tokens.size() > 1) {
            // ROT 45
            if (tokens[1] == "ROT" && tokens.size() == 3) {
                double degrees = stod(tokens[2]);
                Matrix<double> mm = Transformation::getROT(M_PI*degrees/180);
                stack.top()->transform(mm);
            } else if (tokens.size() == 4) {
                // TRANSF SCA 1.4142135 1.4143135
                if (tokens[1] == "SCA") {
                    double cx = stod(tokens[2]);
                    double cy = stod(tokens[3]);
                    Matrix<double> mm = Transformation::getSCA(cx, cy);
                    stack.top()->transform(mm);
                // TRANSF TRA 150 100
                } else if (tokens[1] == "TRA") {
                    double cx = stod(tokens[2]);
                    double cy = stod(tokens[3]);
                    Matrix<double> mm = Transformation::getTRA(cx, cy);
                    stack.top()->transform(mm);
                } else if (tokens[1] == "SHA") {
                    double cx = stod(tokens[2]);
                    double cy = stod(tokens[3]);
                    Matrix<double> mm = Transformation::getSHA(cx, cy);
                    stack.top()->transform(mm);
                } else {
                    cout << "[ERROR] Transformation not recognized." << endl;
                    return -1;
                }
            } else {
                cout << "[ERROR] Transformation not recognized." << endl;
                return -1;
            }
        // COPY
        } else if (cmd == "COPY" && tokens.size() == 1) {
            Shape* newShape = stack.top()->clone();
            stack.push(newShape);
        // GROUP 2
        } else if (cmd == "GROUP" && tokens.size() == 2) {
            int N = stoi(tokens[1]);
            ShapeStack grouped_stack;
            for (int i = 0; i < N; i++) {
                Shape* shp = stack.top();
                stack.pop();
                grouped_stack.push(shp);
//                for (int j = 0; j < grouped_stack.size(); j++)
//                    cout << j << " " << grouped_stack.shapes[i]->color << endl;
//                cout << endl;
            }
            stack.push(new Group(grouped_stack));
        // SHOW 200 300
        } else if (cmd == "SHOW" && tokens.size() == 3) {
            string svg_part = stack.top()->draw();
            int width = stoi(tokens[1]);
            int height = stoi(tokens[2]);

            ofstream output_file_svg;
            output_file_svg.open("output.svg");
            output_file_svg <<
                    R"(<?xml version="1.0" encoding="UTF-8"?>)" << endl <<
                    R"(<svg xmlns="http://www.w3.org/2000/svg" width=")" << width << R"(" height=")" << height << "\">" << endl <<
                    "<path d=\"M 0 0 L" << width << " 0 L" << width << " " << height << " L 0 " << height << "\" fill=\"#cccccc\"/>" << endl <<
                    svg_part << endl <<
                    R"(<rect x="0" y="0" width=")" << width << R"(" height=")" << height << R"(" stroke="#999999" fill="none" stroke-width="1"/>)" << endl <<
                    "</svg>";
            cout <<
                            R"(<?xml version="1.0" encoding="UTF-8"?>)" << endl <<
                            R"(<svg xmlns="http://www.w3.org/2000/svg" width=")" << width << R"(" height=")" << height << "\">" << endl <<
                            "<path d=\"M 0 0 L" << width << " 0 L" << width << " " << height << " L 0 " << height << "\" fill=\"#cccccc\"/>" << endl <<
                            svg_part << endl <<
                            R"(<rect x="0" y="0" width=")" << width << R"(" height=")" << height << R"(" stroke="#999999" fill="none" stroke-width="1"/>)" << endl <<
                            "</svg>";
            output_file_svg.close();
            return 0;
        } else {
            cout << "[ERROR] Command not recognized: " << cmd << endl;
            return -1;
        }
    }

    return 0;
}