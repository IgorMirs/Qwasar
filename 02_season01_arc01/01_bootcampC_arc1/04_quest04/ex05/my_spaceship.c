char* my_spaceship(char* param_1) {
    char* directions[] = {"up", "right", "down", "left"};
    int cur_dir = 0;
    int x = 0, y = 0;
    while(*param_1 != 0) {
        switch(*param_1) {
            case 'R':
                cur_dir = (cur_dir + 1) % 4;
                break;
            case 'L':
                cur_dir--;
                cur_dir = (cur_dir < 0) ? 3 : cur_dir;
                break;
            case 'A':
                switch (cur_dir) {
                    case 0:
                        y--;
                        break;
                    case 1:
                        x++;
                        break;
                    case 2:
                        y++;
                        break;
                    case 3:
                        x--;
                        break;
                    
                    default:
                        break;
                    }
                break;
        }
        param_1++;
    }
    //forming the output string
    char* res = (char*)malloc(100);
    sprintf(res, "{x: %d, y: %d, direction: '%s'}", x, y, directions[cur_dir]);
    return res;
}
