class MoveBehavior {
    public:
        virtual void move() const = 0; 
};

class Side: public MoveBehavior {
    public:
        void move() const override {
            std::cout << "moving side-to-side" << std::endl;
        }
};

class UpDown: public MoveBehavior {
    public:
        void move() const override {
            std::cout << "moving up-to-down" << std::endl;
        }
};

class Attack {
    public:
        virtual void attack() const = 0;
};

class Shooting: public Attack {
    public:
        void attack() const override {
            std::cout << "shooting" << std::endl;
        }
};

class Enemy {
    public:
        float pos_x = 0;
        float pos_y = 0;
        float width = 2;
        float height =2;

        MoveBehavior* moveBehavior;
        Attack* attackBehavior;

    public:
        void performMove(){
            moveBehavior->move();
        }

        void performAttack(){
            attackBehavior->attack();
        }

        void setNewMove(MoveBehavior* mb){
            moveBehavior = mb;
        }

        void setNewAttack(Attack* att){
            attackBehavior = att;
        }
        
};

class Nova: public Enemy{
    public:
        float x = 0;
        float y = 0;
        float width = 4;
        float height =4;

    public:
        Nova(){
            moveBehavior    = new UpDown();
            attackBehavior  = new Shooting();
        }

        void Hello(){
            std::cout << "Hi, I am nova" << std::endl;
        }
        
        void setProps(float x, float y, float width, float height){
            this->x= x;
            this->y= y;
            this->width=width;
            this->height=height;
        }

        void props(){
            std::cout << this->x << std::endl;
            std::cout << this->y << std::endl;
            std::cout << this->width << std::endl;
            std::cout << this->height<< std::endl;
        }
};

class Killer: public Enemy {
    public:
        Killer(){
            moveBehavior    = new UpDown();
            attackBehavior  = new Shooting();
        }
};

struct Button_State {
	bool is_down;
	bool changed;
};

enum {
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_LEFT,
	BUTTON_RIGHT,

	BUTTON_COUNT,
};

struct Input {
	float pos_x = 0;
    float pos_y = 0;
 
    float width = 4;
    float height =4;

    std::string numbuffer = "";

    Button_State buttons[BUTTON_COUNT];
};
