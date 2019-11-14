#include <iostream>
#include <cmath>
#include "block.h"


#define DIGITS 1   // Desired number of pi digits

int main() {
    
    long long collisionCounter = 0;
    std::cout << "calculating:" << std::endl;
    
    block block1(50, cvPoint(100, 750), 0, 1);
    block block2(50, cvPoint(250, 750), -10, pow(100, DIGITS));
    
    cv::Mat background = cv::Mat(800, 800, CV_8UC3, cv::Scalar(255, 255, 255));
    cv::Mat baseBackground = cv::Mat(800, 800, CV_8UC3, cv::Scalar(255, 255, 255));
    cv::line(background, cvPoint(50, 400), cvPoint(50, 750), cvScalar(0, 0, 0), 2);
    cv::line(background, cvPoint(50, 750), cvPoint(750, 750), cvScalar(0, 0, 0), 2);
    
    cvNamedWindow("Main", cv::WINDOW_AUTOSIZE);
    
    
    background.copyTo(baseBackground);

    bool collisions = true;
    
    while(true){


        baseBackground.copyTo(background);
        
        block1.updatePos();
        block2.updatePos();
        
        block1.draw(background);
        block2.draw(background);
        cv::imshow("Main", background);
        cvWaitKey(50);
        
        if (block2.position.x < block1.position.x + block1.width) {
            collisionCounter++;
            block1.newVelocity = ((block1.mass - block2.mass) / (block1.mass + block2.mass) * block1.velocity) + ((2 * block2.mass) / ( block1.mass + block2.mass) * block2.velocity);
            block2.newVelocity = ((2 * block1.mass) / ( block1.mass + block2.mass) * block1.velocity) + ((block2.mass - block1.mass) / (block1.mass + block2.mass) * block2.velocity);
            block1.velocity = block1.newVelocity;
            block2.velocity = block2.newVelocity;
        }
        if (block1.position.x <= 50){
            block1.velocity = -block1.velocity;
            collisionCounter++;
        }
        if (block1.velocity > 0 && block2.velocity > 0 && block2.velocity > block1.velocity){
            double output = collisionCounter / pow(10, DIGITS);
            if(collisions){
                std::cout << "There were " << collisionCounter << " Collisions \n" << "That means Pi is: " << output;
                collisions = false;
            }
        }
    }
}