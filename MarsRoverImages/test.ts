import {Axios, AxiosResponse, AxiosRequestConfig} from 'axios';

const baseUrl = 'https://api.nasa.gov/mars-photos/api/v1/rovers/curiosity/photos';

const axios = new Axios();

function getPhotos(sol:number, page:number = 1, camera?:string, url:string = baseUrl): Promise<AxiosResponse> {
    const config: AxiosRequestConfig = {
        params: {
            sol: sol,
            api_key: 'DEMO_KEY',
            //camera: camera,
            //page: page
        }
    };

    return axios.get(url, config);
}

async function savePhotosFromResponse(response_promise: Promise<AxiosResponse>) {
    const response = await response_promise;
    console.log(`Total photos: ${response.data.total_photos},\nFrom cameras: ${JSON.stringify(response.data.cameras)}`);
}


async function getPhotos2() {
    const apiKey = "DEMO_KEY";
    const apiUrl = "https://api.nasa.gov/mars-photos/api/v1/rovers/curiosity/photos";
    const config: AxiosRequestConfig = {
      params: {
        sol: 1000, // Martian sol (day) on which the photos were taken
        camera: "fhaz", // Camera name
        api_key: apiKey,
      },
    };
    try {
      const response = await axios.get(apiUrl, config);
      console.log(response.data);
    } catch (error) {
      console.error(error);
    }
}
getPhotos2();

//savePhotosFromResponse(getPhotos(1000, 1));