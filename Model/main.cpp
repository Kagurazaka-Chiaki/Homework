// hello


#include "assimp/Importer.hpp"
#include "assimp/Exporter.hpp"
#include "assimp/postprocess.h"
#include "assimp/scene.h"

#include <iostream>
#include <memory>
#include <string>

#include <spdlog/spdlog.h>

#include <filesystem>

#ifdef IMGUI_IMPL_OPENGL_ES2
struct abc {
    int a;
    int b;
};
#endif

struct model {

    aiScene *scene = nullptr;

    model() = default;
};

enum class ModelType {
    PLY,
    OBJ,
    FBX,
    GLTF,
};


// auto LOGGER = spdlog::basic_logger_mt("basic_logger", "logs/basic.txt");

auto DoTheSceneProcessing(aiScene const *scene) -> void {
    spdlog::info("Processing scene: {}", scene->mNumMeshes);

    for (unsigned int i = 0; i < scene->mNumMeshes; ++i) {
        aiMesh const *mesh = scene->mMeshes[i];

        spdlog::info("Processing mesh: {}", mesh->mName.C_Str());
        spdlog::info("Vertices: {}", mesh->mNumVertices);
        spdlog::info("Faces: {}", mesh->mNumFaces);

        // for (unsigned int j = 0; j < mesh->mNumVertices; ++j) {
        //     aiVector3D const &vertex = mesh->mVertices[j];
        //     spdlog::info("Vertex: ({}, {}, {})", vertex.x, vertex.y, vertex.z);
        // }

        // for (unsigned int j = 0; j < mesh->mNumFaces; ++j) {
        //     aiFace const &face = mesh->mFaces[j];
        //     spdlog::info("Face: {}", face.mNumIndices);

        //     for (unsigned int k = 0; k < face.mNumIndices; ++k) {
        //         spdlog::info("Index: {}", face.mIndices[k]);
        //     }
        // }
    }
}

// use assimp to load ply file
auto load_model(std::unique_ptr<model> const &model_ptr, std::string const &file_path) -> bool {
    // Create an instance of the Importer class
    Assimp::Importer importer;

    // And have it read the given file with some example postprocessing
    // Usually - if speed is not the most important aspect for you - you'll
    // probably to request more postprocessing than we do in this example.
    auto scene = importer.ReadFile(
        file_path,
        aiProcess_CalcTangentSpace |
            aiProcess_Triangulate |          
            aiProcess_JoinIdenticalVertices |
            aiProcess_SortByPType
    );

    // If the import failed, report it
    if (nullptr == scene) {
        spdlog::error("Failed to load model: {}", importer.GetErrorString());
        return false;
    }

    // Now we can access the file's contents.
    // DoTheSceneProcessing(scene);

    // We're done. Everything will be cleaned up by the importer destructor
    return true;
}

auto export_model(std::unique_ptr<model> const &model_ptr, std::string const &file_path, const ModelType &type) -> bool {

    Assimp::Exporter exporter;

    auto scene = model_ptr->scene;

    if (nullptr == scene) {
        spdlog::error("Failed to export model: scene is null");
        return false;
    }

    aiReturn result;
    switch (type) {
        case ModelType::PLY:
            result = exporter.Export(scene, "ply", file_path);
            break;
        case ModelType::OBJ:
            spdlog::info("Exporting to OBJ");
            result = exporter.Export(scene, "obj", file_path);
            break;
        case ModelType::FBX:
            result = exporter.Export(scene, "fbx", file_path);
            break;
        case ModelType::GLTF:
            result = exporter.Export(scene, "gltf", file_path);
            break;
        default:
            spdlog::error("Failed to export model: unknown model type");
            return false;
    }

    spdlog::info("Export result:");

    if (result != aiReturn_SUCCESS) {
        spdlog::error("Failed to export model: {}", exporter.GetErrorString());
        return false;
    }

    return true;
}

auto get_curr_path(std::string const &folder_name) -> std::filesystem::path {
    auto bin_path = std::filesystem::current_path();
    auto build_path = bin_path.parent_path();
    auto project_path = build_path.parent_path();
    return project_path / folder_name;
}

int main() {

    abc a;
    a.a = 1;

    std::cout << "Hello, World!" << " " << a.a << std::endl;

    // auto playground_path = get_curr_path("Model");

    // auto const model_file_name = std::string("lucy");

    // auto input_path = playground_path / (model_file_name + ".ply");

    // try {
    //     // Create an instance of the Importer class
    //     Assimp::Importer importer;

    //     // And have it read the given file with some example postprocessing
    //     // Usually - if speed is not the most important aspect for you - you'll
    //     // probably to request more postprocessing than we do in this example.
    //     auto scene = importer.ReadFile(
    //         input_path.string(),
    //         aiProcess_CalcTangentSpace |
    //             aiProcess_Triangulate |          
    //             aiProcess_JoinIdenticalVertices |
    //             aiProcess_SortByPType
    //     );

    //     // If the import failed, report it
    //     if (nullptr == scene) {
    //         spdlog::error("Failed to load model: {}", importer.GetErrorString());
    //     } else {
    //         spdlog::info("Loaded model: {}", input_path.string());
    //     }

    //     Assimp::Exporter exporter;

    //     auto output_path = playground_path / (model_file_name + ".obj");

    //     auto result = exporter.Export(scene, "obj", output_path.string());

    //     if (result != aiReturn_SUCCESS) {
    //         spdlog::error("Failed to export model: {}", exporter.GetErrorString());
    //     } else {
    //         spdlog::info("Exported model to: {}", output_path.string());
    //     }

    // } catch (std::exception const &e) {
    //     spdlog::error("Exception: {}", e.what());
    
    // }

    return 0;
}