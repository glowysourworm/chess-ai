# chess-ai

Possible Strategies:

- Canonical brute force try with alpha-beta pruning
- Board value map based on computer strategy or machine learning

  1) How much is this tile worth for the nth turn / counter-turn
  
  2) How much WAS this tile worth given historical data for 
     a PARTICULAR board configuration. How much material did
     the move lead to for the player?
     
  3) Value maps that are more-or-less static to attempt user-configured
     computer strategies. "How can I make the computer value tiles differently
     based on how I think about my OWN strategy"
   
Data Considerations:

- Lookup / compression of a particular board configuration into minimum key-data storage.
- Copying / multi-threaded execution of the strategy.
- Native execution and storage of memory to maximize efficiency.
