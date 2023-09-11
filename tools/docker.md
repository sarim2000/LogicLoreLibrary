# Docker

Docker is a platform that allows developers to package, distribute, and manage applications inside lightweight, portable containers.

- Docker uses package to deliver software and this is known as **Containers** :
    - This containers are isolated from each other, meaning, they have their own repos.
- Each Container contains its own **Images**
    - This images are nothing but repo containing their own files and systems
- Dockerfile: A script with commands to assemble an image.
- Docker Hub: A cloud-based registry to share Docker images.

## Why to use docker?

1. it solves the dependency issue; by keeping the dependency in its own container thus not depending on outside..
2. storage efficient too as it runs directly on os rather than sharing the resources with os

## commands

### pull
```docker
docker pull <image name>
```

### run
```
docker run <image name>
```

## dockerfile example
```
# Use an official Python runtime as the parent image
FROM python:3.7-slim

# Set working directory
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Install any needed packages specified in requirements.txt
pip install -r requirements.txt

# Make port 80 available to the world outside this container
EXPOSE 80

# Run app.py when the container launches
CMD ["python", "app.py"]
```

## build 

```
docker build -t your_image_name .
```

# sequence of building
1. Build Phase: You use a Dockerfile to define how an image should be built. The command docker build -t your_image_name . is used to create this image. At this stage, you're essentially creating the blueprint.

2. Run Phase: Once you have an image, you can create and run a container from it using the docker run command. This is where you turn that blueprint (image) into a running process (container).