#ifndef COLLISIONBASEDPICALCULATOR_BLOCK_H
#define COLLISIONBASEDPICALCULATOR_BLOCK_H

#include <opencv2/opencv.hpp>

class block {
public:
    int width;
    cv::Point position;
    double velocity;
    double mass;
    double newVelocity;

    block(int Width, const cv::Point& Position, double Velocity, double Mass){
        width = Width;
        position = Position;
        velocity = Velocity;
        mass = Mass;
        newVelocity = 0;
    }

    void updatePos(){
        position.x += (int)velocity;
    }
    
    void draw(cv::Mat background){
        cv::rectangle(background, position, cvPoint(position.x + width, position.y - width), cvScalar(0, 0, 0), -1);

    }
    
};

#endif //COLLISIONBASEDPICALCULATOR_BLOCK_H
