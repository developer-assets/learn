function getSleepHours(day) {
  day = day.toLowerCase();
  switch(day) {
    case 'monday':
    return 6;
    case 'tuesday':
    return 4;
    case 'wednesday':
    return 6;
    case 'thursday':
    return 5;
    case 'friday':
    return 5;
    case 'saturday':
    return 2;
    case 'sunday':
    return 8;
    default:
    return 'Unidentified day of the week.';
  }
}

function getActualSleepHours() {
  let actual = 0;
  actual += getSleepHours('monday');
  actual += getSleepHours('tuesday');
  actual += getSleepHours('wednesday');
  actual += getSleepHours('thursday');
  actual += getSleepHours('friday');
  actual += getSleepHours('saturday');
  actual += getSleepHours('sunday');
  return actual;
}

function getIdealSleepHours() {
  let idealHours = 8;
  return idealHours * 7;
}

function calculateSleepDept() {
  let actualSleepHours = getActualSleepHours();
  let idealSleepHours = getIdealSleepHours();

  if(actualSleepHours === idealSleepHours) {
    console.log('Your sleep hours is good.');
  } else if(actualSleepHours < idealSleepHours) {
    console.log(`You aint getting enough sleep. You miss ${idealSleepHours - actualSleepHours}hrs of sleep a week`);
  } else {
    console.log(`You are over-sleeping. You get ${actualSleepHours - idealSleepHours}hrs of extra sleep a week`);
  }
}

calculateSleepDept();
