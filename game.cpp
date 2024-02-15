

internal void 
simulate_game(Input *input,std::vector<Nova*>& enemies, std::vector<Block*>& Blocks){
    using std::cout;
    using std::endl;

    clear_screen(COLOR_DARK_GRAY);
    
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
        for(int i;i<BUTTON_COUNT;i++){
            if(enemies[0]->buttons[i].changed){
                cout << enemies.size() << " enemies" << endl;
                enemies[0]->buttons[i].changed = false;
            }
        }
        

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
    
    for(int i;i<BUTTON_COUNT; i++){
        if(input->mode_switch == true){

            if(input->phantom_mode == true){
                cout << "entering phantom" << endl;
            } else if(input->capture_mode == true){
                cout << "entering capturer"<< endl;
            } else if(input->dancing_mode== true){
                cout << "entering dancer"  << endl;
            }    
            
            input->mode_switch = false;
        }
    }

    for(int i;i<BUTTON_COUNT;i++){
        input->buttons[i].changed = false;
    }
    
    if(Blocks.size() > 0){
        for(auto& Block: Blocks){
            draw_rect(Block->pos_x,Block->pos_y,Block->width,Block->height,Block->color);
            if(Block->new_block){
                cout << Blocks.size() << " blocks" << endl;
                Block->new_block = false;
            }
        }
        
    }
    
	draw_rect(input->pos_x, input->pos_y, input->width, input->height, input->color);
}

