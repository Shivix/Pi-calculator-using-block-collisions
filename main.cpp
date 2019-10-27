#include <iostream>
#include <cmath>

#define DIGITS 6    // Desired number of pi digits



class block {
public:
    int width;
    double position;
    double velocity;
    double mass;
    double newVelocity;
    
    block(int Width, double Position, double Velocity, double Mass){
        width = Width;
        position = Position;
        velocity = Velocity;
        mass = Mass;
        newVelocity = 0;
    }
    
    void updatePos(){
        position += velocity;
    }

    
};

int main() {
    
    long long collisionCounter = 0;
    std::cout << "calculating:" << std::endl;
    
    block block1(5, 10, 0, 1);
    block block2(5, 200, -10, pow(100, DIGITS));
    
    while(true){
        
        block1.updatePos();
        block2.updatePos();
        if (block2.position < block1.position + block1.width) {
            collisionCounter++;
            block1.newVelocity = ((block1.mass - block2.mass) / (block1.mass + block2.mass) * block1.velocity) + ((2 * block2.mass) / ( block1.mass + block2.mass) * block2.velocity);
            block2.newVelocity = ((2 * block1.mass) / ( block1.mass + block2.mass) * block1.velocity) + ((block2.mass - block1.mass) / (block1.mass + block2.mass) * block2.velocity);
            block1.velocity = block1.newVelocity;
            block2.velocity = block2.newVelocity;
        }
        if (block1.position <= 0){
            block1.velocity = -block1.velocity;
            collisionCounter++;
        }
        if (block1.velocity > 0 && block2.velocity > 0 && block2.velocity > block1.velocity){
            std::cout << collisionCounter << std::endl;
            break;
        }
    }
}