﻿/*
 * Utils.h
 *
 *  Created on: 2020-05-01
 *      Author: AnnaSkyWalker
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>

#include <opencv2/features2d.hpp>
#include "PnPProblem.h"

// Draw a text with the question point
void _declspec(dllexport) drawQuestion(cv::Mat image, cv::Point3f point, cv::Scalar color);

// Draw a text with the number of entered points
void _declspec(dllexport) drawText(cv::Mat image, std::string text, cv::Scalar color);

// Draw a text with the number of entered points
void _declspec(dllexport) drawText2(cv::Mat image, std::string text, cv::Scalar color);

// Draw a text with the frame ratio
void _declspec(dllexport) drawFPS(cv::Mat image, double fps, cv::Scalar color);

// Draw a text with the frame ratio
void _declspec(dllexport) drawConfidence(cv::Mat image, double confidence, cv::Scalar color);

// Draw a text with the number of entered points
void _declspec(dllexport) drawCounter(cv::Mat image, int n, int n_max, cv::Scalar color);

// Draw 6Dof
void _declspec(dllexport) draw6DoF(cv::Mat image, cv::Mat trans, cv::Mat angle, bool good_measurement=true);

// Draw the points and the coordinates
void _declspec(dllexport) drawPoints(cv::Mat image, std::vector<cv::Point2f> &list_points_2d, std::vector<cv::Point3f> &list_points_3d, cv::Scalar color);

// Draw only the 2D points
void _declspec(dllexport) draw2DPoints(cv::Mat image, std::vector<cv::Point2f> &list_points, cv::Scalar color);

// Draw an arrow into the image
void _declspec(dllexport) drawArrow(cv::Mat image, cv::Point2i p, cv::Point2i q, cv::Scalar color, int arrowMagnitude = 9, int thickness=1, int line_type=8, int shift=0);

// Draw the 3D coordinate axes
void _declspec(dllexport) draw3DCoordinateAxes(cv::Mat image, const std::vector<cv::Point2f> &list_points2d);

// Draw the object mesh
void _declspec(dllexport) drawObjectMesh(cv::Mat image, const Mesh *mesh, PnPProblem *pnpProblem, cv::Scalar color);

// Computes the norm of the translation error
double _declspec(dllexport) get_translation_error(const cv::Mat &t_true, const cv::Mat &t);

// Computes the norm of the rotation error
double _declspec(dllexport) get_rotation_error(const cv::Mat &R_true, const cv::Mat &R);

// Converts a given Rotation Matrix to Euler angles
cv::Mat _declspec(dllexport) rot2euler(const cv::Mat & rotationMatrix);

// Converts a given Euler angles to Rotation Matrix
cv::Mat _declspec(dllexport) euler2rot(const cv::Mat & euler);

// Converts a Rotation Matrix to angles along three axises
cv::Mat _declspec(dllexport) rot2angle(const cv::Mat& rotationMatrix);

// Converts a given string to an integer
int _declspec(dllexport) StringToInt ( const std::string &Text );

// Converts a given float to a string
std::string _declspec(dllexport) FloatToString ( float Number );

// Converts a given integer to a string
std::string _declspec(dllexport) IntToString ( int Number );

void _declspec(dllexport) createFeatures(const std::string &featureName, int numKeypoints, cv::Ptr<cv::Feature2D> &detector, cv::Ptr<cv::Feature2D> &descriptor);

cv::Ptr<cv::DescriptorMatcher> _declspec(dllexport) createMatcher(const std::string &featureName, bool useFLANN);

//Create a cube ply file
void _declspec(dllexport) createCubePly(const std::vector<float> size, const std::string filename);

#endif /* UTILS_H_ */
