const jsonString = ``;

const jsObject = JSON.parse(jsonString);


jsObject.map((prov) => {
    console.log(prov['provinceCode'], prov['provinceNameEn'].replace(/ /g, '-'));
});
