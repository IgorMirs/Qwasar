function my_spaceship(param_1) {
    length = param_1.length;
    cur_direct = 0;
    directions = ["up", "right", "down", "left"];
    var x = 0, y = 0;
    for (var i = 0; i < length; i++) {
        switch(param_1[i]) {
            case 'A':
                if (directions[cur_direct] == "up") {
                    y--;
                }
                else if (directions[cur_direct] == "right") {
                    x++;
                }
                else if (directions[cur_direct] == "down") {
                    y++;
                }
                else {
                    x--;
                }
                break;
            case 'R':
                cur_direct = (cur_direct + 1) % 4;
                break;
            case 'L':
                cur_direct = (--cur_direct < 0) ? 3 : cur_direct;
                break;
        }
    }
    return ("{x: " + x + ", y: " + y + ", direction: '" + directions[cur_direct] 
                    + "'}");  
}