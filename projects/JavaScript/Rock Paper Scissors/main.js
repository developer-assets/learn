console.log('hi');

function getUserChoice(userInput) {
  userInput = userInput.toLowerCase();
  if(userInput === 'rock' || userInput === 'paper' || userInput === 'scissors') {
    return userInput;
  } else {
    console.log('Wrong pick.');
  }
}

function getComputerChoice() {
  let choice = Math.floor(Math.random() * 3);
  if (choice === 0) {
    return 'rock';
  }
  else if (choice === 1) {
    return 'paper';
  } else {
    return 'scissors';
  }
}

function determineWinner(userChoice, computerChoice) {
  if (userChoice === computerChoice) {
    return 'Its a tie.';
  }
  if(userChoice === 'rock') {
    if(computerChoice === 'paper') {
      return 'Computer won.';
    } else {
      return 'User won.';
    }
  }
  if(userChoice === 'paper') {
    if(computerChoice === 'scissors') {
      return 'Computer won.';
    } else {
      return 'User won.';
    }
  }
  if(userChoice === 'scissors') {
    if(computerChoice === 'rock') {
      return 'Computer won.';
    } else {
      return 'User won.';
    }
  }
}

function playGame() {
  let userChoice = 'rock';
  if(userChoice === 'bomb') {
    console.log('You won.');
  } else {
    userChoice = getUserChoice(userChoice);
    let computerChoice = getComputerChoice();
    console.log(determineWinner(userChoice, computerChoice));
  }
}

playGame();
