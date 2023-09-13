#include "excel_exporter.h"

void ExcelExporter::GenerateCellBlock(const std::vector<std::unique_ptr<ExerciseSession>>& sessions, int start_row, int start_col, xlnt::worksheet& ws)
{
    int session_number = 1;
    int row_offset = 0;

    for (const auto& seshPtr : sessions) {
        
        const auto& sesh = *seshPtr;
        
        xlnt::range_reference mergeRange(xlnt::cell_reference(start_col, start_row + row_offset),
                                         xlnt::cell_reference(start_col + 3, start_row + row_offset));
        ws.merge_cells(mergeRange);
        
        auto merged_header = ws.cell(xlnt::cell_reference(start_col, start_row + row_offset));
        merged_header.value("Session " + std::to_string(session_number));
        
        row_offset++;

        for (const auto& lift_info : sesh.getLifts()) {
            auto name_cell = ws.cell(xlnt::cell_reference(start_col, start_row + row_offset));
            auto info_cell = ws.cell(xlnt::cell_reference(start_col + 1, start_row + row_offset));
            //auto set_cell = ws.cell(xlnt::cell_reference(start_col + 1, start_row + row_offset));
            //auto rep_cell = ws.cell(xlnt::cell_reference(start_col + 2, start_row + row_offset));
            //auto intensity_cell = ws.cell(xlnt::cell_reference(start_col + 3, start_row + row_offset));

            name_cell.value(lift_info->lift->GetName());

            std::string lift_info_string;
            make_info_string(*lift_info, &lift_info_string);

            info_cell.value(lift_info_string);

            //set_cell.value(lift_info->number_of_sets);
            //rep_cell.value(lift_info->number_of_reps);
            //intensity_cell.value(lift_info->percent_intensity);

            row_offset++;
        }

        session_number++;
    }
}
