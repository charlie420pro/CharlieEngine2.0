struct VS_INPUT
{
	float3 position: POSITION;
	float2 texCoord : TEXCOORD;
};

struct VS_OUTPUT
{
	float4 position : SV_POSITION;
	float2 texCoord : TEXCOORD;
};

VS_OUTPUT VSMain(VS_INPUT vsInput)
{
	VS_OUTPUT output;
	output.position = float4(vsInput, 1);
	output.texCoord = vsInput.texCoord;
	return output;
}