#include "lift.h"

std::string Lift::GetName() const
{
    return name_;
}

std::string Lift::GetDescription() const
{
    return description_;
}

std::shared_ptr<Lift> Lift::GetBaseLift() const
{
    return base_lift_.lock();
}

void Lift::SetName(const std::string& name)
{
    name_ = name;
}

void Lift::SetDescription(const std::string& desc)
{
    description_ = desc;
}

void Lift::SetBaseLift(const std::shared_ptr<Lift>& b_lift)
{
    base_lift_ = b_lift;
}
