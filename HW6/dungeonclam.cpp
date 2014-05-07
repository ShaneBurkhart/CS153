//***********************************************//
// Shane Burkhart
// CS153 Section A
// HW6
//***********************************************//

#include<iostream>
#include<fstream>

bool is_valid(char** map, int x, int y, int width, int height){
  if(map == NULL) return false;
  if(x < 0 || x >= width) return false;
  if(y < 0 || y >= height) return false;
  return map[x][y] == ' ';
}


bool dfs(char** map, int x, int y, int end_x, int end_y, const int width, const int height){
  /* Generic DFS search for any search */
  // No map.
  if(map == NULL) return false;
  // Check if coords are valid.  If not let the stack know we have no path.
  if(!is_valid(map, x, y, width, height)) return false;

  // Mark spot as path.  Do before check if we are there because
  // we still have to travel to that spot.
  map[x][y] = '.';

  // If we found the spot we let the stack know.
  if(x == end_x && y == end_y) return true;

  // Check the path to every adjacent positiion
  if(dfs(map, x + 1, y, end_x, end_y, width, height))
    return true;
  if(dfs(map, x - 1, y, end_x, end_y, width, height))
    return true;
  if(dfs(map, x, y + 1, end_x, end_y, width, height))
    return true;
  if(dfs(map, x, y - 1, end_x, end_y, width, height))
    return true;

  map[x][y] = ' '; // If doesn't have a successful path from coord then set back to empty.
  return false; // Let stack know that we didn't find a path.
}

bool find_path(char** map, int width, int height){
  /* A wrapper for our generic dfs search that is catered to our problem. */
  int start_x = -1;
  int start_y = -1;
  int end_x = -1;
  int end_y = -1;
  bool found_path = false;

  // Find start and end.  We pass this to the dfs search.
  for(int y = 0; y < height; ++y){
    for(int x = 0; x < width; ++x){
      if(map[x][y] == 'Z'){
        start_x = x;
        start_y = y;
      }
      if(map[x][y] == 'E'){
        end_x = x;
        end_y = y;
      }
    }
  }

  // If no start or end found, then we have an invalid map.
  if(start_x == -1 || start_y == -1 || end_x == -1 || end_y == -1) return false;

  // Set the start and end to empty because our dfs search only knows that blanks are valid.
  map[start_x][start_y] = ' ';
  map[end_x][end_y] = ' ';

  // Record whether or not we found a path.  In this problem should always work.
  found_path = dfs(map, start_x, start_y, end_x, end_y, width, height);

  // Mark start and end again.
  map[start_x][start_y] = 'Z';
  map[end_x][end_y] = 'E';

  return found_path;
}

void print_maze(char** map, int width, int height){
  /* Print the maze. */
  for(int y = 0; y < height; ++y){
    for(int x = 0; x < width; ++x)
      std::cout << map[x][y] << " ";
    std::cout << std::endl;
  }
}

int main(){
  int width = -1;
  int height = -1;
  int start_x = 0, start_y = 0;
  char** maze = NULL;

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

    if(width == 0 && height == 0) break;

    file.ignore();

    maze = new char*[width];
    for(int x = 0; x < width; ++x)
      maze[x] = new char[height];

    for(int y = 0; y < height; ++y){
      for(int x = 0; x < width; ++x)
        file.get(maze[x][y]);
      file.ignore();
    }

    // Won't check if found path since the problem should always have a path.
    find_path(maze, width, height);

    print_maze(maze, width, height);

    for(int x = 0; x < width; ++x)
      delete []maze[x];
    delete []maze;

    std::cout << std::endl;
  }

  file.close();

  return 0;
}

