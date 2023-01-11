const fileInput = document.getElementById('plik');
const loadButton = document.getElementById('loadButton');
let fileContent = null;
const saveButton = document.getElementById("saveButton");
const addButton = document.querySelector('[name="addButton"]');
let seria = document.getElementById('seria');
let segment = document.getElementById('segment');
let model = document.getElementById('model');
let pojemnosc = document.getElementById('pojemnosc');
let uklad = document.getElementById('uklad');
let spalanie = document.getElementById('spalanie');
let data = document.getElementById('data');
const deleteCarButton = document.getElementById('deleteCarButton');
const modifyCarButton = document.getElementById('modifyCarButton');
const warning1 = document.getElementById('warning1');
const warning2 = document.getElementById('warning2');
const warning3 = document.getElementById('warning3');
const warning4 = document.getElementById('warning4');
const warning5 = document.getElementById('warning5');
const warning6 = document.getElementById('warning6');
const warning7 = document.getElementById('warning7');
const warning8 = document.getElementById('warning8');
var isLoaded = false;
var isCarValid = false;
var isModifyCarValid = false;

function loadFile() {
    const [file] = fileInput.files;

    const url = URL.createObjectURL(file);
    const resp = new XMLHttpRequest();
    resp.open("GET", url, false);
    resp.setRequestHeader("Content-Type", "text/xml");
    resp.send(null);

    const xmlDoc = resp.responseXML;
    fileContent = xmlDoc;
    addDeleteOptions();
    isLoaded = true;
}

function handleSaveButton() {
    if (fileContent === null) {
        return alert("Nie wczytano pliku XML.");
    }

    const serializer = new XMLSerializer();
    const serializedString = serializer.serializeToString(fileContent);

    const blob = new Blob([serializedString], { type: "text/xml" });
    const link = document.createElement("a");
    link.href = URL.createObjectURL(blob);
    link.download = "xml.xml";
    link.click();
}

function addDeleteOptions() {
    removeOptions();

    // Add options to the "seria" dropdown menu
    const seriaSelect = document.getElementById('seria');
    const serie = fileContent.querySelector('serie');
    for (const seria of serie.children) {
        const option = document.createElement("option");
        option.text = seria.getAttribute('seriaID');
        seriaSelect.add(option);
    }

    // Add options to the "delete car" dropdown menu
    const deleteCarSelect = document.getElementById('deleteCar');
    const cars = fileContent.querySelector('samochody');
    for (const car of cars.children) {
        const option = document.createElement("option");
        option.text = car.getAttribute('seriaID');
        deleteCarSelect.add(option);
    }

    // Add options to the "modify car" dropdown menu
    const modifyCarSelect = document.getElementById('modifyCar');
    for (const car of cars.children) {
        const option = document.createElement("option");
        option.text = car.getAttribute('seriaID');
        modifyCarSelect.add(option);
    }


}

function addCar() {
  validateCar();

}


function deleteCar() {
    var id = document.getElementById('deleteCar').value;
    var cars = fileContent.querySelector('samochody');
    cars.removeChild(cars.children[id-1]);
    addDeleteOptions();
}


function removeOptions() {
    const selectElements = [
        document.getElementById('seria'),
        document.getElementById('deleteCar'),
        document.getElementById('modifyCar')
    ];

    for (const select of selectElements) {
        while (select.firstChild) {
            select.removeChild(select.firstChild);
        }
    }
}

function modifyCar() {
  validateModifyCar();

}


function validateCar() {
    isCarValid = true;

    // Clear the warning messages
    warning1.innerHTML = "";
    warning2.innerHTML = "";
    warning3.innerHTML = "";
    warning4.innerHTML = "";

    // Validate the input fields
    if (seria === "") {
        warning1.innerHTML = "Please select a series";
        isCarValid = false;
    }
    if (segment === "") {
        warning2.innerHTML = "Please select a segment";
        isCarValid = false;
    }
    if (model === "") {
        warning3.innerHTML = "Please enter a model name";
        isCarValid = false;
    }
    if (pojemnosc === "" || isNaN(pojemnosc)) {
        warning4.innerHTML = "Please enter a valid capacity";
        isCarValid = false;
    }
    if (uklad === "") {
        warning5.innerHTML = "Please enter a layout";
        isCarValid = false;
    }
    if (spalanie === "" || isNaN(spalanie)) {
        warning6.innerHTML = "Please enter a valid fuel consumption";
        isCarValid = false;
    }
    if (data === "") {
        warning7.innerHTML = "Please select a registration date";
        isCarValid = false;
    }
    return isCarValid;
}

function validateModifyCar() {
    isModifyCarValid = true;

    var nowaSeria = document.getElementById('nowaSeria');
    var nowySegment = document.getElementById('nowySegment');
    var noweSpalanie = document.getElementById('noweSpalanie');
    var nowaPojemnosc = document.getElementById('nowaPojemnosc');

    // Clear the warning messages
    warning5.innerHTML = "";
    warning6.innerHTML = "";
    warning7.innerHTML = "";
    warning8.innerHTML = "";

    // Validate the input fields
    if (nowaSeria.value === "") {
        warning5.innerHTML = "Please select a series";
        isModifyCarValid = false;
    }
    if (nowySegment.value === "") {
        warning6.innerHTML = "Please select a segment";
        isModifyCarValid = false;
    }
    if (noweSpalanie.value === "") {
        warning7.innerHTML = "Please enter a model name";
        isModifyCarValid = false;
    }
    if (nowaPojemnosc.value === "" || isNaN(nowaPojemnosc.value)) {
        warning8.innerHTML = "Please enter a valid capacity";
        isModifyCarValid = false;
    }
    return isModifyCarValid;
}

document.addEventListener("DOMContentLoaded", () => {
    loadButton.addEventListener("click", loadFile);
    saveButton.addEventListener("click", handleSaveButton);
  addButton.addEventListener('click',addCar);
    addButton.addEventListener('click',addDeleteOptions);
    deleteCarButton.addEventListener('click',deleteCar);
    modifyCarButton.addEventListener('click',modifyCar);
});
