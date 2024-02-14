

internal void 
simulate_game(Input *input,std::vector<Nova*>& enemies){
    using std::cout;
    using std::endl;

    clear_screen(0xff5500);
    
    int step = 1;
    if(input->buttons[BUTTON_UP].is_down){
        if((input->numbuffer) == ""){
            (input->pos_y)+=step;
        } else {
            step = stoi(input->numbuffer);
            (input->pos_y)+=step;
            step = 1;
        }
    }

    if(input->buttons[BUTTON_DOWN].is_down){
        if((input->numbuffer) == ""){
            (input->pos_y)-=step;
        } else {
            step = stoi(input->numbuffer);
            (input->pos_y)-=step;
            step = 1;
        }
    }

    if(input->buttons[BUTTON_LEFT].is_down){
        if((input->numbuffer) == ""){
            (input->pos_x)-=step;
        } else {
            step = stoi(input->numbuffer);
            (input->pos_x)-=step;
            step = 1;
        }
    }
    if(input->buttons[BUTTON_RIGHT].is_down){
        if((input->numbuffer) == ""){
            (input->pos_x)+=1;
        } else {
            step = stoi(input->numbuffer);
            (input->pos_x)+=step;
            step = 1;
        }
    }
    
       
    

    if(enemies.size() > 0){
        cout << enemies.size() << " enemies" << endl;

        if(enemies[0]->buttons[BUTTON_J].is_down){
            (enemies[0]->pos_x)-=1;
        }

        if(enemies[0]->buttons[BUTTON_L].is_down){
            (enemies[0]->pos_x)+=1;
        }
    
        if(enemies[0]->buttons[BUTTON_I].is_down){
            (enemies[0]->pos_y)+=1;
        }

        if(enemies[0]->buttons[BUTTON_K].is_down){
            (enemies[0]->pos_y)-=1;
        }

        draw_rect(enemies[0]->pos_x, enemies[0]->pos_y, enemies[0]->width, enemies[0]->height, 0x7611c3);

    } 
    
	draw_rect(input->pos_x, input->pos_y, input->width, input->height, 0x7611c3);
}

