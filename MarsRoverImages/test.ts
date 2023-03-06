import {Axios, AxiosResponse} from 'axios';

const baseUrl = 'https://api.nasa.gov/mars-photos/api/v1/rovers/curiosity/photos';

const axios = new Axios();

function getPhotos(sol:number, page:number = 1, camera:string | undefined = undefined): Promise<AxiosResponse> {
    const config = {
        params: {
            sol: sol,
            api_key: 'DEMO_KEY',
            //camera: camera,
            //page: page
        }
    };


    return axios.get(baseUrl, config)
}

async function savePhotosFromResponse(response_promise: Promise<AxiosResponse>) {
    const response = await response_promise;
    console.log(`Total photos: ${response.data.total_photos},\nFrom cameras: ${JSON.stringify(response.data.cameras)}`);
}

savePhotosFromResponse(getPhotos(1000, 1));