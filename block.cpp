#include "block.hpp"

block::block(int width, const cv::Point& position, double velocity, double mass){
    this->width = width;
    this->position = position;
    this->velocity = velocity;
    this->mass = mass;
}

block::~block()= default;

void block::draw(cv::Mat background) const{
    cv::rectangle(background, position, cvPoint(position.x + width, position.y - width), cvScalar(0, 0, 0), -1);
}

void block::updatePos(){
    position.x += (int)velocity;
}


