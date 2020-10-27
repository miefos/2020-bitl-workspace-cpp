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
                Matrix<double> vv(3,1); // column vector has 3 rows, 1 column
                Shape* theShape = stack.top();
                // loop throuh all points
                for (int i = 0; i < theShape->n; i++) {
                    vv.a[0][0] = theShape->points[i]->a[0][0]; // old x
                    vv.a[1][0] = theShape->points[i]->a[0][1]; // old y
                    vv.a[2][0] = 1; // always 1
                    Matrix<double> ww = mm*vv;
                    double new_x = ww.a[0][0];
                    double new_y = ww.a[1][0];
                    theShape->points[i]->a[0][0] = new_x;
                    theShape->points[i]->a[0][1] = new_y;
                }
            } else if (tokens.size() == 4) {
                // TRANSF SCA 1.4142135 1.4143135
                if (tokens[1] == "SCA") {
                    double cx = stod(tokens[2]);
                    double cy = stod(tokens[3]);
                    Matrix<double> mm = Transformation::getSCA(cx, cy);
                    Matrix<double> vv(3,1); // column vector has 3 rows, 1 column
                    Shape* theShape = stack.top();
                    // loop throuh all points
                    for (int i = 0; i < theShape->n; i++) {
                        vv.a[0][0] = theShape->points[i]->a[0][0]; // old x
                        vv.a[1][0] = theShape->points[i]->a[0][1]; // old y
                        vv.a[2][0] = 1; // always 1
                        Matrix<double> ww = mm*vv;
                        double new_x = ww.a[0][0];
                        double new_y = ww.a[1][0];
                        theShape->points[i]->a[0][0] = new_x;
                        theShape->points[i]->a[0][1] = new_y;
                    }

                // TRANSF TRA 150 100
                } else if (tokens[1] == "TRA") {
                    double cx = stod(tokens[2]);
                    double cy = stod(tokens[3]);
                    Matrix<double> mm = Transformation::getTRA(cx, cy);
                    Matrix<double> vv(3,1); // column vector has 3 rows, 1 column
                    Shape* theShape = stack.top();
                    // loop throuh all points
                    for (int i = 0; i < theShape->n; i++) {
                        vv.a[0][0] = theShape->points[i]->a[0][0]; // old x
                        vv.a[1][0] = theShape->points[i]->a[0][1]; // old y
                        vv.a[2][0] = 1; // always 1
                        Matrix<double> ww = mm*vv;
                        double new_x = ww.a[0][0];
                        double new_y = ww.a[1][0];
                        theShape->points[i]->a[0][0] = new_x;
                        theShape->points[i]->a[0][1] = new_y;
                    }

                } else if (tokens[1] == "SHA") {
                    double cx = stod(tokens[2]);
                    double cy = stod(tokens[3]);
                    Matrix<double> mm = Transformation::getSHA(cx, cy);
                    Matrix<double> vv(3,1); // column vector has 3 rows, 1 column
                    Shape* theShape = stack.top();
                    // loop throuh all points
                    for (int i = 0; i < theShape->n; i++) {
                        vv.a[0][0] = theShape->points[i]->a[0][0]; // old x
                        vv.a[1][0] = theShape->points[i]->a[0][1]; // old y
                        vv.a[2][0] = 1; // always 1
                        Matrix<double> ww = mm*vv;
                        double new_x = ww.a[0][0];
                        double new_y = ww.a[1][0];
                        theShape->points[i]->a[0][0] = new_x;
                        theShape->points[i]->a[0][1] = new_y;
                    }

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
            }
            stack.push(new Group(grouped_stack));
        // SHOW 200 300
        } else if (cmd == "SHOW" && tokens.size() == 3) {
            // output s.top().draw() (surround with a few more SVG lines)
            //<?xml version="1.0" encoding="UTF-8"?>
            //<svg xmlns="http://www.w3.org/2000/svg" width="100" height="100">
            //<path d="M 0 0 L 100 0 L 100 100 L 0 100" fill="#cccccc"/>
            //<path d="M 100 50 L 50 0 L 0 50 L 50 100" fill="#0000ff"/>
            //<path d="M 100 50 L 25 93.3 L 25 6.7" fill="#ff0000"/>
            //<rect x="0" y="0" width="100" height="100"
            //stroke="#999999" fill="none" stroke-width="1"/>
            //</svg>

            string svg_part = stack.top()->draw();
            int width = stoi(tokens[1]);
            int height = stoi(tokens[2]);

            ofstream output_file_svg;
            output_file_svg.open("test1out.svg");
            output_file_svg <<
                    R"(<?xml version="1.0" encoding="UTF-8"?>)" << endl <<
                    R"(<svg xmlns="http://www.w3.org/2000/svg" width=")" << width << R"(" height=")" << height << "\">" << endl <<
                    "<path d=\"M 0 0 L" << width << " 0 L" << width << " " << height << " L 0 " << height << "\" fill=\"#cccccc\"/>" << endl <<
                    svg_part << endl <<
                    R"(<rect x="0" y="0" width=")" << width << R"(" height=")" << height << R"(" stroke="#999999" fill="none" stroke-width="1"/>)" << endl <<
                    "</svg>";
            output_file_svg.close();
            return 0;
        } else {
            cout << "[ERROR] Command not recognized." << endl;
            return -1;
        }
//        cout << Line << endl;
    }

    return 0;
}