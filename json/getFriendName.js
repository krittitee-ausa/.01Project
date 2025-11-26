const fs = require('node:fs');
var data = ``
var provinceCode = [10, 
11, 
12, 
13, 
14, 
15, 
16, 
17, 
18, 
19, 
20, 
21, 
22, 
23, 
24, 
25, 
26, 
27, 
30, 
31, 
32, 
33, 
34, 
35, 
36, 
37, 
38, 
39, 
40, 
41, 
42, 
43, 
44, 
45, 
46, 
47, 
48, 
49, 
50, 
51, 
52, 
53, 
54, 
55, 
56, 
57, 
58, 
60, 
61, 
62, 
63, 
64, 
65, 
66, 
67, 
70, 
71, 
72, 
73, 
74, 
75, 
76, 
77, 
80, 
81, 
82, 
83, 
84, 
85, 
86, 
90, 
91, 
92, 
93, 
94, 
95, 
96]

const toNormalNameFormat = (uppercaseName) => {
    if (!uppercaseName) {
        return ""; // Handle empty or null input
    }

    // 1. Convert the entire string to lowercase first
    const lower = uppercaseName.toLowerCase();

    // 2. Split the string by spaces to get an array of words
    const words = lower.split(' ');

    // 3. Map over the words to apply capitalization
    const formattedWords = words.map(word => {
        // Handle potential empty strings from multiple spaces
        if (word.length === 0) {
            return '';
        }

        // Capitalize the first letter and concatenate the rest of the word
        // charAt(0).toUpperCase() gets the first char capitalized
        // slice(1) gets the rest of the word
        return word.charAt(0).toUpperCase() + word.slice(1);
    });

    // 4. Join the words back together with a space
    return formattedWords.join(' ');
};

var splitText = data.split('\t')
var allFriends = splitText.filter(Text => !(Text.includes("DEPARTMENT") || Text.includes("@") || Text.includes("Enrolled") || Text.includes("\n") || Text.includes("68")))
console.log(allFriends.length);
console.log(provinceCode.length)

var baseMaxTime = 1764150034
var baseMinTime = 1764150034 - (3 * 31556952)
var dayMinTime = 1.25*86400
var dayMaxTime = 5*86400
function getRandomNumber(min, max) {
  // Ensure min and max are integers and handle potential non-numeric inputs
  min = Math.ceil(min);
  max = Math.floor(max);
  // Generate a random number between min (inclusive) and max (inclusive)
  return Math.floor(Math.random() * (max - min + 1)) + min;
}
function shuffle(array) {
  let currentIndex = array.length;

  // While there remain elements to shuffle...
  while (currentIndex != 0) {

    // Pick a remaining element...
    let randomIndex = Math.floor(Math.random() * currentIndex);
    currentIndex--;

    // And swap it with the current element.
    [array[currentIndex], array[randomIndex]] = [
      array[randomIndex], array[currentIndex]];
  }
}

try {
    fs.writeFileSync('./json/DataGenerate/DeliveredPackageData.txt', '');
    console.log(`Successfully created/cleared file: DeliveredPackageData`);
} catch (err) {
    console.error(`Error creating/clearing file: DeliveredPackageData`, err);
    return; // Exit if file cannot be created
}

try {
    fs.writeFileSync('./json/DataGenerate/onGoingPackage.txt', '');
    console.log(`Successfully created/cleared file: onGoingPackage`);
} catch (err) {
    console.error(`Error creating/clearing file: onGoingPackage`, err);
    return; // Exit if file cannot be created
}

try {
    fs.writeFileSync('./json/DataGenerate/counter.txt', '');
    console.log(`Successfully created/cleared file: counter`);
} catch (err) {
    console.error(`Error creating/clearing file: counter`, err);
    return; // Exit if file cannot be created
}

var ExportDataDelivered = []
var ExportDataOnGoing = []
var DeliveredCount = 0
var OnGoingCount = 0
allFriends.map((NameSender) => {
    allFriends.map((NameReceiver) => {

        var From = provinceCode[Math.floor(Math.random()*provinceCode.length)].toString()
        var To = provinceCode[Math.floor(Math.random()*provinceCode.length)].toString()

        const probability = 5 / 100;
        if (Math.random() < probability) {
            var startTime = getRandomNumber(baseMaxTime-(86400*1.5), baseMaxTime);
            ExportDataOnGoing.push({
                Sender: toNormalNameFormat(NameSender),
                Receiver: toNormalNameFormat(NameReceiver), 
                ID: `${From}${To}${startTime.toString().slice(-6)}`,
                From: From,
                To: To,
                Time: startTime.toString()
            })
        } else {
            var startTime = getRandomNumber(baseMinTime, baseMaxTime-(86400*5.5));
            var EndTime = startTime + getRandomNumber(dayMinTime, dayMaxTime);
            ExportDataDelivered.push({
                Sender: toNormalNameFormat(NameSender), 
                Receiver: toNormalNameFormat(NameReceiver), 
                ID: `${From}${To}${startTime.toString().slice(-6)}`,
                From: From,
                To: To,
                TimeStart: startTime.toString(),
                TimeEnd: EndTime.toString()
            })
        }

    })
});
shuffle(ExportDataDelivered)
ExportDataDelivered.map((AData) => {
    const dataString = 
        `${AData.Sender}\n` +
        `${AData.Receiver}\n` +
        `${AData.ID}\n` +
        `${AData.From}\n` +
        `${AData.To}\n` +
        `${AData.TimeStart}\n` +
        `${AData.TimeEnd}\n`

    try {
        // Append the string to the file synchronously
        fs.appendFileSync('./json/DataGenerate/DeliveredPackageData.txt', dataString);
    } catch (err) {
        console.error('Error writing to file: DeliveredPackageData.txt', err);
    }
    DeliveredCount++;
});

shuffle(ExportDataOnGoing)
ExportDataOnGoing.map((AData) => {
    const dataString = 
        `${AData.Sender}\n` +
        `${AData.Receiver}\n` +
        `${AData.ID}\n` +
        `${AData.From}\n` +
        `${AData.To}\n` +
        `${AData.Time}\n`

    try {
        // Append the string to the file synchronously
        fs.appendFileSync('./json/DataGenerate/onGoingPackage.txt', dataString);
    } catch (err) {
        console.error('Error writing to file: onGoingPackage.txt ', err);
    }
    OnGoingCount++;
});

try {
    fs.appendFileSync('./json/DataGenerate/counter.txt', `${OnGoingCount} ${DeliveredCount}`);
} catch (err) {
    console.error('Error writing to file: counter.txt ', err);
}