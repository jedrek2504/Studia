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
let score = 0;
let collisionSound = document.getElementById('collisionSound');

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
        const type = randomNumber();

        if(type === 1)
        {
            this.y = CANVAS_HEIGHT - 25;
            this.width = 50;
            this.height = 50;
        }
        if(type === 2)
        {
            this.y = CANVAS_HEIGHT - 25;
            this.width = 25;
            this.height = 50;
        }
        if(type === 3)
        {
            this.y = CANVAS_HEIGHT - 40;
            this.width = 25;
            this.height = 50;
        }
    }

    update() {
        this.x -= 5;
    }

    draw() {
        const color = randomNumber();
        ctx.fillStyle = 'green';
        ctx.fillRect(this.x, this.y, this.width, this.height);
    }
}

// Event handlers
document.getElementById('startGame').addEventListener('click', startGame);

document.getElementById('playAgain').addEventListener('click', resetGame);

document.addEventListener('keydown', event => {
    if (event.code === 'Space') {
        dino.jump();
    }
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
}

// Start the game
function startGame() {
    // Hide the main menu
    document.getElementById('mainMenu').style.display = 'none';

    // Start game loop
    requestAnimationFrame(loop);
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
                collisionSound.currentTime = 0;
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
    // Hide the game over screen
    document.getElementById('gameOver').style.display = 'none';

    // Reset game variables
    frameCount = 0;
    dino.x = 100;
    dino.y = 100;
    dino.velocity = 0;
    obstacles = [];
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

