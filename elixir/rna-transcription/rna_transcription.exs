defmodule RNATranscription do
  @doc """
  Transcribes a character list representing DNA nucleotides to RNA

  ## Examples

  iex> RNATranscription.to_rna('ACTG')
  'UGAC'
  """
  @spec to_rna([char]) :: [char]
  def to_rna(dna) do
    str = to_string(dna)
    str |> String.replace("A", "U")
      |> String.replace("T", "A")
      |> String.replace("G", "Z")
      |> String.replace("C", "G")
      |> String.replace("Z", "C")
      |> to_charlist
  end
end
