#ifndef COLLISIONBASEDPICALCULATOR_BLOCK_HPP
#define COLLISIONBASEDPICALCULATOR_BLOCK_HPP

#include <opencv2/opencv.hpp>

class block {
public:
    int width;
    cv::Point position;
    double velocity;
    double mass;
    double newVelocity = 0;

    block(int, const cv::Point&, double, double);
    ~block();

    void updatePos();

    void draw(cv::Mat) const;

};


#endif //COLLISIONBASEDPICALCULATOR_BLOCK_HPP
