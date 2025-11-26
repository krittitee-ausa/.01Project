const fs = require('node:fs');
var data = `
\t68070501001\tKORNDANAI LIKITPATTANAKUL\tkorndanai.likit@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501002\tKRITTITEE AUSAVADITALERT\trenderways@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501003\tKONRAWACH SATITPOSRE\tkaenhj@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501005\tKUNT SRAPINKORNBUREE\tshogun329159@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501006\tKWANPAPHA KOSAIYAPORN\tmonarita.xx@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501007\tKANAKORN THAIPRAKHON\tnon.kanakorn@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501008\tJAKKRAWUT PRAMSAKSTIAN\tsun32583@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501009\tCHETSADAPHON SRIKUN\tsrikun0604@icloud.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501010\tDHITTHAYA SAIYONT\tnursethitthaya@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501011\tNATAMON CHANSIRISRI\tNattamon.kanom@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled
\t68070501012\tNAPAT SRISAWAD\ttt.phone97946@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501013\tNATTAKIT PROMVISIT\tnattakitikkiw999@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501015\tNATCHANAN KITPRAYOON\tnatchananks@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501016\tTHANAKRIT PHANOMSOMBOON\tnontthanakrit38@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501017\tTHANACHOT THETKAN\tthanachotthetkan2297@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501018\tTHANAPHAT PHETCHARAT\tthanaphat00game@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501019\tTHANAYOT MONTHICHACHAT\tthanayot.zoe@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501020\tTHANATCHA BUTSIMMA\tbutsimmat815@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501021\tTHANANKORN WORANANPOKEN\tpeetz2549@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501022\tTEERAMET THITICHAWALITKUL\ttbe922397@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled
\t68070501023\tNOPPANAT TOKARNKUL\tnoppanat.tokarnkul@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501024\tNARAWIT SANDORN\tnarawit.sand@mail.kmutt.ac.th\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501025\tNIPADA SONTHANAKORN\thetb1412@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501026\tBANYAPON DUANGNOOM\t49427@taweethapisek.ac.th\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501027\tBAOBUSSAKORN CHAREONTHAM\tbuabussakorn2549@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501028\tPOKPONG SITTISAK\tpokpong.sittisak@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501029\tPATIPOL PONGSAWAT\tpatipolpongsawat1@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501030\tPOONYAPAT ISSARAGKUL NA AYUTTHAYA\tpoint505sdg@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501031\tPIAMSIRI KASEMSOMJAI\tsszflxstudy@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501032\tPHONGSAKON SRIWICHA\tphongsakon.sriw@mail.kmutt.ac.th\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501033\tPLONLAKIT PAN-IAM\tnikyrayongppoo@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501034\tPHITCHAYAPHA VITTAYAVANICH\tphitchayapha.vitta@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501035\tPICHAMON MUROH\tpichamon.muro@mail.kmutt.ac.th\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501036\tPIPATPONG SAPTHARANON\tpipatpong.sapt@mail.kmutt.ac.th\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501037\tFENTPICH CHEERA\tfentpich.jeera@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501038\tPHUDINAN PHUKAKUN\tdffda344567@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501040\tPOORI TECHATREESUKHON\tpoori.rigi@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501041\tPHUREE TEEKAPAKVISIT\talmonddelicate@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501042\tYOTSARAN XU\twarintron152521@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501043\tRATCHAKRIT MOJOMSIN\trachakritmojomsin@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501044\tWACHIRAWIT PHUPHA\twachirawitphupha@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501045\tVORAMATE KITTICHOTIRUT\tvoramate05@outlook.co.th\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501046\tWARATTRA VIPOOSIRIKUP\twarattravip@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501047\tWOLFGANG MARTIN MAUTENDORFER\twolfgang13092549@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501048\tWIT KULLAWAN\tkullawanwit@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501049\tVEERADET SOMTOB\tveeradetsomtob@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501050\tSASILAKHA NGERNYANGDANG\tj6528f@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501051\tSIWACH GUTTRA\tsiwatgear.014@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501052\tSUPAROEK KERDRATTANAPRON\thopehut8826@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501053\tSORRAWIT SANGNGERN\tmbb4935@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled
\t68070501054\tSIPAKORN BOONYA-A-RAK\tsipakorn.acc@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501055\tSIRAWIT NIRARACH\tsirawitnirarach@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501058\tANANYAPHORN NOPNOI\thibarikung1395@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501059\tATTHACHET ANANKUSRI\twin.atthachet@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501060\tAKKHARAWIN PUTAWEE\taonworkfromhome@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501061\tITTHICHET PHUCHAROENSILP\tittichetphu@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501062\tKRITTAPAS CHUDECH\tkrittapaschudech@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501063\tKANTHAPORN KULTHAWEESOMBUT\tjune18072548@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501064\tCHAIYAKORN PRAPANPONGPINIT\tchaiyakorn.mk27@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501065\tCHAIYAWAT JADJANENAVEE\tmickymaxwin@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled
\t68070501066\tNATTACHAI AURMAROON\tnattachai10love@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501067\tNATDANAI CHANGKAN\tNatdanai14700@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501068\tNATTAWAT KARNJANANITHI\toatzajennie2549@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501069\tTHIWAT PANGSARN\tjj0959596763@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501070\tTAPPATIWAT THONGSRI\tteppatiwatts@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501071\tTHANAPAT SEANGJAN\tthanapat.seang@mail.kmutt.ac.th\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501072\tNANO JUNTHAWONG\tnanojuntawong@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501073\tPARINYA SEMSEN\t25304@maesai.ac.th\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501074\tPEETIKORN AMORNRAKSA\tportong2007@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501075\tPONGRAPEE WORASAN\taayaay013@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled
\t68070501076\tPROMPIRIYA PONGSAKUL\tprompiriyap@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501077\tPHATCHALAPON THAMMOL\tpatchalaponthammol@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501078\tPUTHIMETH BOONPORN\thouseputhimet@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501079\tPHURIPHUT RAKPRAKOBKIT\tphuriphutr47@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501080\tPURI YAMKLEEB\tztsunaz.yamkleeb@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501081\tMAHAKIJ LERVIRIYAPHAN\tmaxmax152549@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501082\tRATCHAPHRUEK NINSAKU\trachina1548@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501083\tWARISARA SUCHIN\twarisara0212@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501084\tWAKIN MUKDA\twakin.most1@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501085\tSAKARANAN SRISAWAT\tdinoko2007@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled
\t68070501086\tACHIRA DUANGJAI\tchiefza32@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501087\tONANONG CHADEE\tonanong.chad@kmutt.ac.th\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501088\tISAWAT METHAN\tIsawatmethan@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501089\tJAKRIN KOKSRI\tjakrinkoksri@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501090\tDECHATORN PONGKRAIRUNGRUANG\tthisforctusageagain@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501091\tTHANYAWAT SOMSAI\tlittle15425@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501092\tTEERUT NAKORNCHAI\tteerut.nak@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled\t
\t68070501093\tSUWICHAK SAECHENG\ttan555tan5555@gmail.com\tDEPARTMENT OF COMPUTER ENGINEERING \tEnrolled
    `
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

        if (NameSender != NameReceiver) {
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