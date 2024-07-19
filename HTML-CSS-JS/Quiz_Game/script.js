const quizData = [
    {
        question: "What does HTML stand for?",
        answers: ["Hyper Text Markup Language", "Home Tool Markup Language", "Hyperlinks and Text Markup Language", "Hyper Text Managing Language"],
        correctAnswer: "Hyper Text Markup Language"
    },
    {
        question: "Which HTML attribute specifies an alternate text for an image, if the image cannot be displayed?",
        answers: ["src", "alt", "title", "href"],
        correctAnswer: "alt"
    },
    {
        question: "Which CSS property controls the text size?",
        answers: ["font-size", "text-size", "font-style", "text-style"],
        correctAnswer: "font-size"
    },
    {
        question: "What does CSS stand for?",
        answers: ["Computer Style Sheets", "Cascading Style Sheets", "Colorful Style Sheets", "Creative Style Sheets"],
        correctAnswer: "Cascading Style Sheets"
    },
    {
        question: "Which JavaScript method can be used to add an element to the end of an array?",
        answers: ["push()", "last()", "append()", "addToEnd()"],
        correctAnswer: "push()"
    },
    {
        question: "How do you write 'Hello World' in an alert box?",
        answers: ["msgBox('Hello World');", "alert('Hello World');", "alertBox('Hello World');", "msg('Hello World');"],
        correctAnswer: "alert('Hello World');"
    },
    {
        question: "How do you create a function in JavaScript?",
        answers: ["function myFunction()", "function = myFunction()", "create function myFunction()", "myFunction()"],
        correctAnswer: "function myFunction()"
    },
    {
        question: "Which operator is used to assign a value to a variable?",
        answers: ["x", "=", "*", "-"],
        correctAnswer: "="
    },
    {
        question: "Inside which HTML element do we put the JavaScript?",
        answers: ["<javascript>", "<js>", "<script>", "<scripting>"],
        correctAnswer: "<script>"
    },
    {
        question: "How can you add a comment in a JavaScript?",
        answers: ["'This is a comment", "//This is a comment", "<!--This is a comment-->", "/*This is a comment*/"],
        correctAnswer: "//This is a comment"
    },
    {
        question: "Which event occurs when the user clicks on an HTML element?",
        answers: ["onchange", "onmouseclick", "onmouseover", "onclick"],
        correctAnswer: "onclick"
    },
    {
        question: "Which property is used to change the text color of an element?",
        answers: ["text-color", "font-color", "color", "text-style"],
        correctAnswer: "color"
    },
    {
        question: "How do you round the number 7.25, to the nearest integer?",
        answers: ["Math.rnd(7.25)", "round(7.25)", "Math.round(7.25)", "rnd(7.25)"],
        correctAnswer: "Math.round(7.25)"
    },
    {
        question: "How do you find the number with the highest value of x and y?",
        answers: ["Math.ceil(x, y)", "top(x, y)", "ceil(x, y)", "Math.max(x, y)"],
        correctAnswer: "Math.max(x, y)"
    },
    {
        question: "What is the correct way to write a JavaScript array?",
        answers: ["var colors = ['red', 'green', 'blue']", "var colors = 'red', 'green', 'blue'", "var colors = 'red' + 'green' + 'blue'", "var colors = (1:'red', 2:'green', 3:'blue')"],
        correctAnswer: "var colors = ['red', 'green', 'blue']"
    },
    {
        question: "How do you declare a JavaScript variable?",
        answers: ["variable carName;", "var carName;", "v carName;", "declare carName;"],
        correctAnswer: "var carName;"
    },
    {
        question: "Which operator is used to compare two values?",
        answers: ["==", "<>", "><", "!="],
        correctAnswer: "=="
    },
    {
        question: "What will the following code return: Boolean(10 > 9)",
        answers: ["true", "false", "NaN", "undefined"],
        correctAnswer: "true"
    },
    {
        question: "Which HTML attribute is used to define inline styles?",
        answers: ["styles", "font", "style", "class"],
        correctAnswer: "style"
    },
    {
        question: "How do you select an element with id 'demo' in CSS?",
        answers: ["#demo", ".demo", "demo", "*demo"],
        correctAnswer: "#demo"
    }
];

const questionContainer = document.getElementById('question-container');
const answersContainer = document.getElementById('answers-container');
const nextButton = document.getElementById('next-btn');
const resultContainer = document.getElementById('result');

let currentQuestionIndex = 0;
let score = 0;

function shuffleArray(array) {
    for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
    }
    return array;
}

function showQuestion(questionIndex) {
    const currentQuestion = quizData[questionIndex];
    questionContainer.textContent = currentQuestion.question;

    answersContainer.innerHTML = '';
    shuffleArray(currentQuestion.answers).forEach(answer => {
        const answerButton = document.createElement('button');
        answerButton.textContent = answer;
        answerButton.classList.add('answer-btn');
        answerButton.addEventListener('click', () => checkAnswer(answer, currentQuestion.correctAnswer));
        answersContainer.appendChild(answerButton);
    });
}

function checkAnswer(selectedAnswer, correctAnswer) {
    if (selectedAnswer === correctAnswer) {
        score++;
        resultContainer.textContent = 'Correct!';
    } else {
        resultContainer.textContent = `Wrong! Correct answer is: ${correctAnswer}`;
    }
    disableAnswerButtons();
}

function disableAnswerButtons() {
    const answerButtons = document.querySelectorAll('.answer-btn');
    answerButtons.forEach(button => {
        button.disabled = true;
    });
    nextButton.disabled = false;
}

function enableAnswerButtons() {
    const answerButtons = document.querySelectorAll('.answer-btn');
    answerButtons.forEach(button => {
        button.disabled = false;
    });
    nextButton.disabled = true;
}

function nextQuestion() {
    currentQuestionIndex++;
    if (currentQuestionIndex < quizData.length) {
        showQuestion(currentQuestionIndex);
        resultContainer.textContent = '';
        enableAnswerButtons();
    } else {
        showFinalScore();
    }
}

function showFinalScore() {
    questionContainer.textContent = `Quiz Completed! Your Score: ${score} out of ${quizData.length}`;
    answersContainer.innerHTML = '';
    nextButton.style.display = 'none';
}

nextButton.addEventListener('click', nextQuestion);

// Initialize quiz
showQuestion(currentQuestionIndex);
