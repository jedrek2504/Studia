const buttons = document.querySelectorAll(".button-nav");

buttons.forEach((button, i) =>
    button.addEventListener("click", function () {
        if (!i) document.querySelector(".tasks-grid").scrollIntoView({ behavior: "smooth" });
        else document.querySelector(`.box${i}`).scrollIntoView({ behavior: "smooth" });
    })
);
