const fileInput = document.getElementById('plik');
const loadButton = document.getElementById('loadButton');
let fileContent = null;
const saveButton = document.getElementById("saveButton");
const addButton = document.querySelector('[name="addButton"]');
let model = document.getElementById('model');
let segment = document.getElementById('segment');
let moc = document.getElementById('moc');
let spalanie = document.getElementById('spalanie');
let data = document.getElementById('data');
let cena = document.getElementById('cena');
let seria = document.getElementById('seria');
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
const warning9 = document.getElementById('warning9');
const warning10 = document.getElementById('warning9');
var isLoaded = false;
var isCarValid = false;
var isModifyCarValid = false;
const pozycja = 3;

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
    link.download = "samochody.xml";
    link.click();
}

function removeOptions(){
    const select1 = document.getElementById('deleteCar');
    const select2 = document.getElementById('pickCar');

    var selects = [select1,select2];
    for(var i=0; i<2;i++){
        while(selects[i].firstChild){
            selects[i].removeChild(selects[i].firstChild);
        }
    }

}

function addDeleteOptions() {
    removeOptions();

    const select = document.getElementById('deleteCar');
    var cars = fileContent.querySelector('samochody');
    var i = 1;
    for(const car of cars.children){
        var option = document.createElement("option");
        option.setAttribute('value',i);
        i++;
        option.text = car.children[0].textContent;
        select.add(option);
    }

    const select1 = document.getElementById('pickCar');
    i = 1;
    for(const car of cars.children){
        var option = document.createElement("option");
        option.setAttribute('value',i);
        i++;
        option.text = car.children[0].textContent;
        select1.add(option);
    }
}

function addCar() {
    validateCar();
    if(isCarValid){
        var samochod = fileContent.createElement("samochod");
        var newModel = fileContent.createElement("model");
        var newSegment = fileContent.createElement("segment");
        var newMoc = fileContent.createElement("moc_maksymalna");
        var newSpalanie = fileContent.createElement("srednie_spalanie");
        var newData = fileContent.createElement("pierwsza_rejestracja");
        var newCena = fileContent.createElement("cena");
        newModel.textContent = model.value;
        newSegment.textContent = segment.value;
        newMoc.textContent = moc.value;
        newMoc.setAttribute("jednostka","KM");
        newSpalanie.textContent = spalanie.value;
        newSpalanie.setAttribute("jednostka","l/100km");
        newData.textContent = data.value.replace("-",".");
        newCena.textContent = cena.value;
        samochod.appendChild(newModel);
        samochod.appendChild(newSegment);
        samochod.appendChild(newMoc);
        samochod.appendChild(newSpalanie);
        samochod.appendChild(newData);
        samochod.appendChild(newCena);
        samochod.setAttribute("seriaID", seria.value);
        samochod.setAttribute("pozycja", "P"+pozycja+1);
        fileContent.querySelector("samochody").appendChild(samochod);
    }
}

function deleteCar() {
    var id = document.getElementById('deleteCar').value;
    var cars = fileContent.querySelector('samochody');
    cars.removeChild(cars.children[id-1]);
    addDeleteOptions();
}


function modifyCar() {
    validateModifyCar();
    if(isModifyCarValid){
        var id = document.getElementById('pickCar').value;
        var car = fileContent.querySelector('samochody').children[id-1];
        var newModel = document.getElementById('nowyModel');
        var newSegment = document.getElementById('nowySegment');
        var newMoc = document.getElementById('nowaMoc');
        var newSpalanie = document.getElementById('noweSpalanie');
        var newData = document.getElementById('nowaData');
        var newCena = document.getElementById('nowyCena');
        var features = [newModel,newSegment,newMoc,newSpalanie,newData,newCena];
        var i=0;
        for(const feature of car.children){
            if(features[i].value !=''){
                feature.textContent = features[i].value;
            }
            i++;
        }
    }
}

function validateCar() {
    isCarValid = true;

    // Validate the input fields
    if(!(/^[A-Z]{1}[0-9]{2}$/).test(model.value) || model.value ==""){
        warning1.textContent ="model doesnt match [A-Z]{1}[0-9]{2} ";
        warning1.style.cssText=  "display: block;width: 100%;background-color: #FF2734;text-align: center;padding-top: 10px;padding-bottom: 10px;margin-bottom: 20px;border-radius: 10px;box-shadow: 2px 2px #000;";
        isCarValid= false;
    }
    else{
        warning1.textContent ="";
        warning1.style.cssText="";
    }

    if(!(/^[A-Z]{1}$/).test(segment.value) || segment.value==''){
        warning2.textContent ="segment doesnt match [A-Z]{1}[a-z]{0,14} ";
        warning2.style.cssText=  "display: block;width: 100%;background-color: #FF2734;text-align: center;padding-top: 10px;padding-bottom: 10px;margin-bottom: 20px;border-radius: 10px;box-shadow: 2px 2px #000;";
        isCarValid= false;
    }
    else{
        warning2.textContent ="";
        warning2.style.cssText="";
    }

    if(!(/^[0-9]{1,3}$/).test(moc.value) || moc.value==''){
        warning3.textContent ="moc doesnt match [0-9]{1,3} ";
        warning3.style.cssText=  "display: block;width: 100%;background-color: #FF2734;text-align: center;padding-top: 10px;padding-bottom: 10px;margin-bottom: 20px;border-radius: 10px;box-shadow: 2px 2px #000;";
        isCarValid= false;
    }
    else{
        warning3.textContent ="";
        warning3.style.cssText="";
    }

    if(!(/^[0-9]{1,2}$/).test(spalanie.value) || spalanie.value==''){
        warning4.textContent ="spalanie doesnt match [0-9]{1,2} ";
        warning4.style.cssText=  "display: block;width: 100%;background-color: #FF2734;text-align: center;padding-top: 10px;padding-bottom: 10px;margin-bottom: 20px;border-radius: 10px;box-shadow: 2px 2px #000;";
        isCarValid= false;
    }
    else{
        warning4.textContent ="";
        warning4.style.cssText="";
    }

    if(!(/^[0-9]{1,3}$/).test(cena.value) || cena.value==''){
        warning5.textContent ="cena doesnt match [0-9]{0,8} ";
        warning5.style.cssText=  "display: block;width: 100%;background-color: #FF2734;text-align: center;padding-top: 10px;padding-bottom: 10px;margin-bottom: 20px;border-radius: 10px;box-shadow: 2px 2px #000;";
        isCarValid= false;
    }
    else{
        warning5.textContent ="";
        warning5.style.cssText="";
    }
}

function validateModifyCar() {
    isModifyCarValid = true;

    var nowyModel = document.getElementById('nowyModel');
    var nowySegment = document.getElementById('nowySegment');
    var nowaMoc = document.getElementById('nowaMoc');
    var noweSpalanie = document.getElementById('noweSpalanie');
    var nowyCena = document.getElementById('nowyCena');

    if(!(/^[A-Z]{1}[0-9]{2}$/).test(nowyModel.value) || nowyModel.value ==""){
        warning6.textContent ="model doesnt match [A-Z]{1}[0-9]{2} ";
        warning6.style.cssText=  "display: block;width: 100%;background-color: #FF2734;text-align: center;padding-top: 10px;padding-bottom: 10px;margin-bottom: 20px;border-radius: 10px;box-shadow: 2px 2px #000;";
        isCarValid= false;
    }
    else{
        warning6.textContent ="";
        warning6.style.cssText="";
    }

    if(!(/^[A-Z]{1}$/).test(nowySegment.value) || nowySegment.value==''){
        warning7.textContent ="segment doesnt match [A-Z]{1}[a-z]{0,14} ";
        warning7.style.cssText=  "display: block;width: 100%;background-color: #FF2734;text-align: center;padding-top: 10px;padding-bottom: 10px;margin-bottom: 20px;border-radius: 10px;box-shadow: 2px 2px #000;";
        isCarValid= false;
    }
    else{
        warning7.textContent ="";
        warning7.style.cssText="";
    }

    if(!(/^[0-9]{1,3}$/).test(nowaMoc.value) || nowaMoc.value==''){
        warning8.textContent ="moc doesnt match [0-9]{1,3} ";
        warning8.style.cssText=  "display: block;width: 100%;background-color: #FF2734;text-align: center;padding-top: 10px;padding-bottom: 10px;margin-bottom: 20px;border-radius: 10px;box-shadow: 2px 2px #000;";
        isCarValid= false;
    }
    else{
        warning8.textContent ="";
        warning8.style.cssText="";
    }

    if(!(/^[0-9]{1,2}$/).test(noweSpalanie.value) || noweSpalanie.value==''){
        warning9.textContent ="spalanie doesnt match [0-9]{1,2} ";
        warning9.style.cssText=  "display: block;width: 100%;background-color: #FF2734;text-align: center;padding-top: 10px;padding-bottom: 10px;margin-bottom: 20px;border-radius: 10px;box-shadow: 2px 2px #000;";
        isCarValid= false;
    }
    else{
        warning9.textContent ="";
        warning9.style.cssText="";
    }

    if(!(/^[0-9]{1,8}$/).test(nowyCena.value) || nowyCena.value==''){
        warning10.textContent ="cena doesnt match [0-9]{0,8}'.00' ";
        warning10.style.cssText=  "display: block;width: 100%;background-color: #FF2734;text-align: center;padding-top: 10px;padding-bottom: 10px;margin-bottom: 20px;border-radius: 10px;box-shadow: 2px 2px #000;";
        isCarValid= false;
    }
    else{
        warning10.textContent ="";
        warning10.style.cssText="";
    }
}

document.addEventListener("DOMContentLoaded", () => {
    loadButton.addEventListener("click", loadFile);
    saveButton.addEventListener("click", handleSaveButton);
    addButton.addEventListener('click',addCar);
    addButton.addEventListener('click',addDeleteOptions);
    deleteCarButton.addEventListener('click',deleteCar);
    modifyCarButton.addEventListener('click',modifyCar);
});
