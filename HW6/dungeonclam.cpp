//***********************************************//
// Shane Burkhart
// CS153 Section A
// HW6
//***********************************************//

#include<iostream>
#include<fstream>

bool is_valid(char** map, int x, int y){
  return map[x][y] == ' ' || map[x][y] == 'E';
}


bool dfs(char** map, int x, int y, const int width, const int height){
  if(map[x][y] == 'E') return true;

  if(map[x][y] != 'Z')
    map[x][y] = '.';

  if(x + 1 < width && is_valid(map, x + 1, y)){
    if(dfs(map, x + 1, y, width, height))
      return true;
    map[x + 1][y] = 'v';
  }
  if(x - 1 >= 0 && is_valid(map, x - 1, y)){
    if(dfs(map, x - 1, y, width, height))
      return true;
    map[x - 1][y] = 'v';
  }
  if(y + 1 < height && is_valid(map, x, y + 1)){
    if(dfs(map, x, y + 1, width, height))
      return true;
    map[x][y + 1] = 'v';
  }
  if(y - 1 >= 0 && is_valid(map, x, y - 1)){
    if(dfs(map, x, y - 1, width, height))
      return true;
    map[x][y - 1] = 'v';
  }
  return false;
}

int main(){
  int width = -1;
  int height = -1;
  int start_x = 0, start_y = 0;
  char** maze;

  // ****************************************//
  // Read from cin!!!!!!!!!!
  for(int i = 0; i < 10; ++i)
    std::cout << "READ FROM CIN!!!!!!!!!" << std::endl;
  // ****************************************//

  std::fstream file;

  file.open("sampleinput.txt");

  while(width != 0 && height != 0){
    file >> width;
    file >> height;
    std::cout << "Size of maze is " << width << " x " << height << std::endl;

    file.ignore();

    maze = new char*[width];
    for(int x = 0; x < width; ++x)
      maze[x] = new char[height];

    for(int y = 0; y < height; ++y){
      for(int x = 0; x < width; ++x){
        file.get(maze[x][y]);
        if(maze[x][y] == 'Z'){
          start_x = x;
          start_y = y;
        }
      }
      file.ignore();
    }

    std::cout << "Starting position: (" << start_x << ", " << start_y << ")" << std::endl;

    dfs(maze, start_x, start_y, width, height);

    for(int y = 0; y < height; ++y){
      for(int x = 0; x < width; ++x)
        std::cout << maze[x][y] << " ";
      std::cout << std::endl;
    }

    std::cout << std::endl;
  }

  file.close();

  return 0;
}

