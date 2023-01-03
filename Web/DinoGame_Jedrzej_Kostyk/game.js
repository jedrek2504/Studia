// Constants
const CANVAS_WIDTH = 600;
const CANVAS_HEIGHT = 150;
const GRAVITY = 0.25;
const JUMP_VELOCITY = -8;

// Global variables
let canvas;
let ctx;
let frameCount = 0;
let dino;
let obstacles = [];
let obstacleSpeed = 3;
let score = 0;
let collisionSound = document.getElementById('collisionSound');
let jumpSound = document.getElementById('jumpSound');
let mainMenuSound = document.getElementById('mainMenuSound');

// Classes
class Dino {
    constructor() {
        this.x = 100;
        this.y = 100;
        this.width = 50;
        this.height = 50;
        this.velocity = 0;
    }

    update() {
        // Apply gravity
        this.velocity += GRAVITY;

        // Update position
        this.y += this.velocity;

        // Check if dino is on the ground
        if (this.y + this.height > CANVAS_HEIGHT) {
            this.y = CANVAS_HEIGHT - this.height;
            this.velocity = 0;
        }
    }

    draw() {
        ctx.fillStyle = 'black';
        ctx.fillRect(this.x, this.y, this.width, this.height);
    }

    jump() {
        this.velocity = JUMP_VELOCITY;
    }
}

class Obstacle {
    constructor() {
        this.x = CANVAS_WIDTH;
        const obstacleType = randomNumber();
        const colorType = randomNumber();
        const colors = ['red', 'blue', 'green'];

        if(obstacleType === 1)
        {
            this.y = CANVAS_HEIGHT - 25;
            this.width = 50;
            this.height = 50;
            this.color = colors[colorType - 1];
        }
        if(obstacleType === 2)
        {
            this.y = CANVAS_HEIGHT - 25;
            this.width = 25;
            this.height = 50;
            this.color = colors[colorType - 1];
        }
        if(obstacleType === 3)
        {
            this.y = CANVAS_HEIGHT - 40;
            this.width = 25;
            this.height = 50;
            this.color = colors[colorType - 1];
        }
    }

    update() {
        this.x -= obstacleSpeed;
    }

    draw() {
        ctx.fillStyle = this.color;
        ctx.fillRect(this.x, this.y, this.width, this.height);
    }
}

// Event handlers
document.getElementById('startGame').addEventListener('click', startGame);

document.getElementById('playAgain').addEventListener('click', resetGame);

document.addEventListener('keydown', event => {
    if (event.code === 'Space') {
        dino.jump();
        jumpSound.currentTime = -0.5;
        jumpSound.play();
    }
});

document.addEventListener('click', function() {
    mainMenuSound.play();
});

// Functions

// Initialization
function init() {
    // Create canvas
    canvas = document.getElementById('gameCanvas');
    ctx = canvas.getContext('2d');

    // Create dino
    dino = new Dino();

    // Show main menu
    showMainMenu();
}

// Show the main menu
function showMainMenu() {
    document.getElementById('mainMenu').style.display = 'block';

    console.log("weed");
    // Start main menu music
    mainMenuSound.currentTime = 0;
    mainMenuSound.play();
    mainMenuSound.volume = 0.3;
}

// Start the game
function startGame() {
    // Hide the main menu
    document.getElementById('mainMenu').style.display = 'none';

    // Start game loop
    requestAnimationFrame(loop);

    // Start increasing obstacle speed every second
    setInterval(function() {
        obstacleSpeed += 0.2;
    }, 1000);
}

// Update the score
function updateScore() {
    score++;
    document.getElementById('score').innerHTML = score;
}

function checkCollision() {
    for (const obstacle of obstacles) {
        // Check for horizontal collision
        if (dino.x < obstacle.x + obstacle.width && dino.x + dino.width > obstacle.x) {
            // Check for vertical collision
            if (dino.y < obstacle.y + obstacle.height && dino.y + dino.height > obstacle.y) {
                // Collision detected!
                collisionSound.currentTime = -0.6;
                collisionSound.play();
                return true;
            }
        }
    }
    return false;
}

// Show the game over screen
function showGameOver() {
    document.getElementById('gameOver').style.display = 'block';
    document.getElementById('finalScore').innerHTML = score;
}

// Reset the game
function resetGame() {
    // Start music again
    mainMenuSound.currentTime = -0.5;
    mainMenuSound.play();
    mainMenuSound.volume = 0.5;
    // Hide the game over screen
    document.getElementById('gameOver').style.display = 'none';

    // Reset game variables
    frameCount = 0;
    dino.x = 100;
    dino.y = 100;
    dino.velocity = 0;
    obstacles = [];
    obstacleSpeed = 3;
    score = 0;

    // Restart game loop
    requestAnimationFrame(loop);
}

//generates a random number between {1, 2, 3}
function randomNumber() {
    return Math.floor(Math.random() * 3) + 1;
}

// Game loop
function loop() {

    updateScore()

    // Check for game over
    if (checkCollision()) {
        showGameOver();
        mainMenuSound.currentTime = -0.5;
        mainMenuSound.pause();
        return;
    }

    // Clear canvas
    ctx.clearRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);

    // Update and draw objects
    dino.update();
    dino.draw();

    for (const obstacle of obstacles) {
        obstacle.update();
        obstacle.draw();
    }

    // Generate new obstacles
    if (frameCount % 100 === 0) {
        obstacles.push(new Obstacle());
    }

    // Remove off-screen obstacles
    obstacles = obstacles.filter(obstacle => obstacle.x + obstacle.width > 0);

    // Increment frame count
    frameCount++;

    // Request next frame
    requestAnimationFrame(loop);
}

// Function init() call
init();