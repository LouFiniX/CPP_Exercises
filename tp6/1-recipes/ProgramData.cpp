#include "ProgramData.hpp"


void ProgramData::add_material(std::string name)
{
    _materials.emplace_back(std::make_unique<Material>(std::move(name)));
}

void ProgramData::get_materials(std::vector<const Material*>& materials) const
{
    for (const auto& material:_materials){
        if (material != nullptr) {
            materials.emplace_back(material.get());
        }
    }
}

void ProgramData::register_recipe(std::vector<std::string> materials, std::vector<std::string> products)
{
    _recipes.emplace_back(std::make_unique<Recipe>(materials, products, _recipes.size() + 1));
    std::cout << "Recipe " << *(_recipes.back().get()) << "has been registered" << std::endl;
}

bool ProgramData::is_doable_recipes(const Recipe& recipe) const
{
    for (const auto& material:recipe.get_materials()){
        bool have_material = false;
        for (const auto& our_material:_materials){
            if (our_material != nullptr && our_material.get()->get_name() == material){
                have_material = true;
                break;
            }
        }
        if (!have_material){
            return false;
        }
    }
    return true;
}


void ProgramData::collect_doable_recipes(std::vector<const Recipe*>& recipes) const
{
    for (const auto& recipe:_recipes){
        if (is_doable_recipes(*recipe.get())){
            recipes.emplace_back(recipe.get());
        }
    }
}

void ProgramData::missing_material_for_recipe(const Recipe& recipe, std::vector<std::string>& missing_material) const
{
    for (const auto& material:recipe.get_materials()){
        bool have_material = false;
        for (const auto& our_material:_materials){
            if (our_material!= nullptr && our_material.get()->get_name() == material){
                have_material = true;
                break;
            }
        }
        if (!have_material){
            missing_material.emplace_back(material);
        }
    }
}

ProductionResult ProgramData::produce(size_t recipe_id)
{
    ProductionResult result;
    if (_recipes.size() >= recipe_id) {
        auto recipe = _recipes[recipe_id - 1].get();
        result.recipe = recipe;
        missing_material_for_recipe(*recipe, result.missing_materials);
        if (result.missing_materials.empty()) {
            for (const auto& material: recipe->get_materials()) {
                for (auto& our_material: _materials) {
                    if (our_material != nullptr && our_material.get()->get_name() == material) {
                        our_material = nullptr;
                    }
                }
            }
            for (const auto &product: recipe->get_product()) {
                add_material(product);
            }
        }
    }
    return result;
}