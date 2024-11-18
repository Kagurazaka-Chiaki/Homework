# RenderDoc Python console, powered by python 3.6.4.
# The 'pyrenderdoc' object is the current CaptureContext instance.
# The 'renderdoc' and 'qrenderdoc' modules are available.
# Documentation is available: https://renderdoc.org/docs/python_api/index.html

import re
import sys
from typing import Dict, List

# Import renderdoc if not already imported (e.g. in the UI)
if "renderdoc" not in sys.modules and "_renderdoc" not in sys.modules:
    import renderdoc

# # Alias renderdoc for legibility
rd = renderdoc # pylint: disable = possibly-used-before-assignment

all_draws = {}  # type: Dict[int, rd.Drawcall]

# Define a recursive function for iterating over actions
def iter_action(d, indent=""):
    """Iterate over the draw's children."""
    # save the drawcall by eventId
    all_draws[d.eventId] = d
    # Iterate over the draw's children
    for d in d.children:
        iter_action(d, indent + "   ")


class ShaderInfo:
    """Class to store information about a shader."""
    def __init__(self, text: str):
        # Initialize all attributes with default values
        self.regex_map_list = [int(x) for x in re.findall(r": (\d+) ", text)]
        # print(f"Regex Map List: {self.regex_map_list}, {len(self.regex_map_list)}")
        self.subgroup_size = self.regex_map_list[0]
        self.instruction_count_all = self.regex_map_list[1]


def get_disassembly_targets(controller) -> str:
    """Get the disassembly targets."""
    targets = controller.GetDisassemblyTargets(True)
    # print(f"Disassembly targets: {targets}")
    for target in targets:
        if "KHR_pipeline_executable_properties" in target:
            print(f"Disassembly target: {target}")
            return target
    return "SPIR-V (RenderDoc)"


def disassemble_shader(controller, eid: int, target: str) -> List[str]:
    """Disassemble the shader."""
    controller.SetFrameEvent(eid, True)
    pipeline_state = controller.GetPipelineState()
    pipeline_object = pipeline_state.GetGraphicsPipelineObject()
    vs_ref = pipeline_state.GetShaderReflection(rd.ShaderStage.Vertex) # pylint: disable = c-extension-no-member
    ps_ref = pipeline_state.GetShaderReflection(rd.ShaderStage.Pixel)  # pylint: disable = c-extension-no-member

    vs_input_sign = vs_ref.readOnlyResources
    for i in vs_input_sign:
        print(f"Input: {i.name}")

    return [
        controller.DisassembleShader(pipeline_object, vs_ref, target),
        controller.DisassembleShader(pipeline_object, ps_ref, target),
    ]


def get_vs_and_ps_info(vs_str: str, ps_str: str, index: int) -> str:
    """Get the vertex and pixel shader information."""
    vs_info = ShaderInfo(vs_str)
    ps_info = ShaderInfo(ps_str)
    all_vs_instruction = vs_info.regex_map_list[index]
    all_ps_instruction = ps_info.regex_map_list[index]
    return f"{all_vs_instruction} / {all_ps_instruction}"


def get_shader_info(controller, target: str, eid: int, index: int) -> str:
    """Get the shader information."""
    [vs_str, ps_str] = disassemble_shader(controller, eid, target)
    return get_vs_and_ps_info(vs_str, ps_str, index)


def sample_code(controller):
    """Sample code to get shader information."""
    print("Here we can use the replay controller")
    sdf = controller.GetStructuredFile()
    print(f"StructuredFile: {sdf}")

    actions = controller.GetRootActions()
    # Iterate over all the root actions
    for d in actions:
        iter_action(d)

    # eid_list = [
    #     329,
    #     333,
    #     339,
    #     345,
    #     351,
    #     357,
    #     362,
    #     366,
    #     372,
    # ]

    # target = get_disassembly_targets(controller)
    # for eid in eid_list:
    #     action = all_draws[eid]
    #     face_count = action.numIndices // 3
    #     print(f"{face_count}")

    # for eid in eid_list:
    #     info = get_shader_info(controller, target, eid, 1)
    #     print(f"{info}")

    # winsystems = [rd.WindowingSystem(i) for i in controller.GetSupportedWindowSystems()] # pylint: disable = c-extension-no-member
    # print(f"Windowing systems: {winsystems}")

    # # This example code works on windows as that's simple to integrate with tkinter
    # if not rd.WindowingSystem.Win32 in winsystems: # pylint: disable = c-extension-no-member
    #     raise RuntimeError("Example requires Win32 windowing system: " + str(winsystems))


    # eid_map_tex = {}
    # all_textures = controller.GetTextures()
    # for tex in all_textures:
    #     # print(f"Texture: {tex.resourceId}")
    #     for i in controller.GetUsage(tex.resourceId):
    #         # print(f"Usage: {i.eventId}")
    #         if i.eventId not in eid_map_tex:
    #             eid_map_tex[i.eventId] = []
    #         eid_map_tex[i.eventId].append(tex.resourceId)

    # for eid in eid_list:
    #     if eid in eid_map_tex:
    #         print(f"Texture: {eid_map_tex[eid]}")
    #         for tex in all_textures:
    #             if tex.resourceId in eid_map_tex[eid]:
    #                 n = pyrenderdoc.GetResourceName(tex.resourceId) # type: ignore # pylint: disable = undefined-variable
    #                 print(f"Texture: {tex.format.Name()} {n}")


if "pyrenderdoc" in globals():
    # ICaptureContext *ctx = pyrenderdoc.CaptureContext()
    print(f"ctx: {pyrenderdoc}")  # type: ignore # pylint: disable = undefined-variable
    pyrenderdoc.Replay().BlockInvoke(sample_code)  # type: ignore # pylint: disable = undefined-variable
else:
    print("Error: pyrenderdoc not found")
