let divisibleByFour = (year) =>
    year mod 4 == 0

let divisibleByOneHundred = (year) =>
    year mod 100 == 0

let divisibleByFourHundred = (year) =>
    year mod 400 == 0

let isLeapYear = (year) =>
    (divisibleByFour(year) && !divisibleByOneHundred(year)) || divisibleByFourHundred(year)
