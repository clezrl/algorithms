/** solve_maze(int** maze, int n)
 * Recursively decides whether the maze is solvable from the given position
 * using backtracking.
 * A maze is solvable if position (n - 1, n - 1)  may be reached from the
 * given position by only moving downward and to the right, but not both at
 * once (i.e. not diagonally). A position in the maze is valid to move to
 * only if it contains a 1.
 */
bool solve_maze(int** maze, int n, int position[2]){
    
    if ((position[0] >= n || position[1] >= n) || maze[position[0]][position[1]] != 1) return false;
    if (position[0] == n-1 && position[1] == n-1) return true;
    
    int right[2] = {position[0] + 1, position[1]};
    int down[2] = {position[0], position[1] + 1};
    
    return solve_maze(maze, n, right) || solve_maze(maze, n, down);
}

/** solve_maze(int** maze, int n)
 * Decides whether the maze is solvable from position (0, 0) by making a call
 * to the recursive function by the same name.
 */
bool solve_maze(int** maze, int n) {
    int position[2] = {0,0};
    return solve_maze(maze, n, position);
}


