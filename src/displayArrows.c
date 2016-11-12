/**
 * @author Maria Hinsche
 * @brief displays in which dircetion the nibo is moving
 */

enum movement {
		BACKWARD,
		FORWARD,
		STOP,
		ROTATION_LEFT,
		ROTATION_RIGHT};

enum direction {
		LEFT,
		RIGHT,
		STRAIGHT};

void displayArrow(int movement, int direction){

	if(movement == STOP && direction == -1){
		gfx_fill(0);
		gfx_move(50, 30);
		gfx_print_text("STOP");
	}
	if(movement == ROTATION_RIGHT && direction == -1){
		gfx_fill(0);
		gfx_move(20, 10);
		gfx_print_text("Rotation right");
		gfx_move(40, 20);
		gfx_lineTo(gfx_get_x() + 30, gfx_get_y());
		gfx_lineTo(gfx_get_x(), gfx_get_y() + 30);
		gfx_lineTo(gfx_get_x() -30 , gfx_get_y());
		gfx_move(gfx_get_x(), gfx_get_y());
		gfx_print_text("<");
	}
	if(movement == ROTATION_LEFT && direction == -1){
		gfx_fill(0);
		gfx_move(20, 10);
		gfx_print_text("Rotation left");
		gfx_move(70, 20);
		gfx_lineTo(gfx_get_x() - 30, gfx_get_y());
		gfx_lineTo(gfx_get_x(), gfx_get_y() + 30);
		gfx_lineTo(gfx_get_x() +30 , gfx_get_y());
		gfx_move(gfx_get_x(), gfx_get_y());
		gfx_print_text(">");
	}
	if(movement == FORWARD && direction == LEFT){
		gfx_fill(0);
		gfx_move(20, 10);
		gfx_print_text("forward left");
		gfx_move(60, 20);
		gfx_lineTo(gfx_get_x() - 20, gfx_get_y() + 30);
		gfx_move(gfx_get_x(), gfx_get_y());
		gfx_print_text("v");
	}
	if(movement == FORWARD && direction == RIGHT){
		gfx_fill(0);
		gfx_move(20, 10);
		gfx_print_text("forward right");
		gfx_move(60, 20);
		gfx_lineTo(gfx_get_x() + 20, gfx_get_y() + 30);
		gfx_move(gfx_get_x(), gfx_get_y());
		gfx_print_text("v");
	}
	if(movement == FORWARD && direction == STRAIGHT){
		gfx_fill(0);
		gfx_move(20, 10);
		gfx_print_text("forward straight");
		gfx_move(60, 20);
		gfx_lineTo(gfx_get_x() , gfx_get_y() + 30);
		gfx_move(gfx_get_x(), gfx_get_y());
		gfx_print_text("v");
	}
	if(movement == BACKWARD && direction == LEFT){
		gfx_fill(0);
		gfx_move(20, 10);
		gfx_print_text("backward right");
		gfx_move(60, 60);
		gfx_lineTo(gfx_get_x() + 20, gfx_get_y() - 40);
		gfx_move(gfx_get_x(), gfx_get_y());
		gfx_print_text("^");
	}
	if(movement == BACKWARD && direction == RIGHT){
		gfx_fill(0);
		gfx_move(20, 10);
		gfx_print_text("backward right");
		gfx_move(60, 60);
		gfx_lineTo(gfx_get_x() - 20, gfx_get_y() - 40);
		gfx_move(gfx_get_x(), gfx_get_y());
		gfx_print_text("^");
	}
	if(movement == BACKWARD && direction == STRAIGHT){
		gfx_fill(0);
		gfx_move(20, 10);
		gfx_print_text("backward straight");
		gfx_move(60, 60);
		gfx_lineTo(gfx_get_x() , gfx_get_y() - 40);
		gfx_move(gfx_get_x(), gfx_get_y());
		gfx_print_text("^");
	}
}

/**
 * @param[in] x
 * @param[in] y
 */
void getMovement(int x, int y){

	if(x < 0 && y < 0)
		getDirection(x,y,BACKWARD);
	if(x > 0 && y > 0)
		getDirection(x,y,FORWARD);
	if(x == 0 && y == 0)
		displayArrow(STOP, -1);
	if(x < 0 && y > 0)
		displayArrow(ROTATION_LEFT, -1);
	if(x > 0 && y < 0)
		displayArrow(ROTATION_RIGHT, -1);
}

/**
 * @param[in] x
 * @param[in] y
 */
void getDirection(int x, int y, int movement){

	if(x > y)
		displayArrow(movement, LEFT);
	if(x < y)
		displayArrow(movement, RIGHT);
	if(x == y)
		displayArrow(movement, STRAIGHT);
}
