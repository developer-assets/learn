// create kelvin as const since it wont be changes and append 293 to it
const kelvin = 293;
// converting kelvin to celcius
let celsius = 293 - 273;
//converting kelvin to fahrenheit
let fahrenheit = celsius * (9/5) + 32;
//convert the fahrenheit to the closest lower or equal whole number
fahrenheit = Math.floor(fahrenheit);
console.log(`The temprature is ${fahrenheit} degrees Fahrenheit`);
