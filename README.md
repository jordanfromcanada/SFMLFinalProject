# SFMLFinalProject

A recreation of the Lunar Lander Atari game using the C++ SFML library.

<img width="712" alt="Screen Shot 2020-10-03 at 2 53 40 PM" src="https://user-images.githubusercontent.com/65370643/95001621-d7d9d300-0588-11eb-99e1-3c2bfdbe233d.png">

<img width="712" alt="Screen Shot 2020-10-03 at 2 55 45 PM" src="https://user-images.githubusercontent.com/65370643/95001634-e7591c00-0588-11eb-8180-fe93461f0f7f.png">

* What classes will you need to create?
    * Game class - encompassing player's game session
    * Spaceship, terrain, user input
* What methods will they need?
  * Game Class
    * getTime()
    * getFuel()
    * getState() - started, running, paused
  * Spaceship class:
    * getPosition()
    * drawPosition()
    * getHorizontalVelocity()
    * getVerticalVelocity()
    * getAltitude()
    * getFuel()
  * Terrain
    * drawTerrain()
    * potentially - bonusZones()
* What data will they need to store?
  * Game Class
     * time elapse, fuel remaining, state of game
  * Spaceship class:
     * current ship position, velocity, altitude
  * Terrain
     * terrain points to detect collisions
* In what order will you implement them?
  * model terrain, model ship, input/ship movement, collision detection, score
* What tests will you write along the way to verify that you're making progress?
  * collision detection tests, input verification tests
