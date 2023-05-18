# Game of Life 

## The Rules

### Forrest terrain
* First Population
- New life if empty cell has 2-4 neighbours
- Dies if cell has less than 2 or more than 5 neighbours

* Second population
- New life if empty cell has 3 neighbours
- Dies if cell has less than 2 or more than 3 neighbours


### Desert terrain
* First population
- New life if empty cell has 3 neighbours
- Dies if cell has less than 2 or more than 3 neighbours

* Second population
- New life if empty cell has 2-4 neighbours
- Dies if cell has less than 2 or more than 4 neighbours

### Fortress
* First population 
- Can acces if cell has 3 or more neighbours

* Second population 
- Can acces if cell has less than 3 neighbours

### Pit
* No one survives