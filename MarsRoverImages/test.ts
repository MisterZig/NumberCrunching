import fetch from "node-fetch";

const baseUrl = "https://api.nasa.gov/mars-photos/api/v1/rovers/curiosity/photos";
/*
async function savePhotosFromResponse(response: {
    total_photos: number;
    cameras: string[];
}) {
    console.log(
        `Total photos: ${
            response.total_photos
        },\nFrom cameras: ${JSON.stringify(response.cameras)}`
    );
}
*/

async function getPhotos2(key:string, sol: number, page: number, camera: string) {
    try {
        const response = await fetch(
            `${baseUrl}?sol=${sol}&api_key=${key}&page=${page}&camera=${camera}`
        );
        const data = await response.json();
        console.log(data);
    } catch (error) {
        console.error(error);
    }
}
const res = getPhotos2("DEMO_KEY", 1000, 1, "FHAZ");
res.then((data) => console.log(data));

//savePhotosFromResponse(getPhotos(1000, 1));
